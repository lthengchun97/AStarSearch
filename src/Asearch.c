#include "Asearch.h"
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "nodehelper.h"

// The follow previous and now node will be set as global variable.
Node *previous;
Node *now;
Node *went;
char* passCountry;
float nowDistance;

float findDistance(Node *current, Node *end){
  float heuristic;
  heuristic = sqrt ( ((current->data->x - end->data->x)*(current->data->x - end->data->x)) + ((current->data->y - end->data->y)*(current->data->y - end->data->y)) );
  //printf("%f\n",heuristic);
  return heuristic;
}

void testDistance(A_Node **current, A_Node *end){
  float temp1,temp2;
  temp1 = findDistance((*current)->left,end);
  temp2 = findDistance((*current)->right,end);
}

Node *Asearch(Node **current, Node *end,int backtrack,float totalDistance){
  float temp1,temp2;
  if(backtrack == 0)
  {
    passCountry=malloc(50);
    strcpy(passCountry,"");
  }

  if(*current == end)
  {
    printf("Total shortest distance :%f\n",totalDistance);
    //printf("Ending point =%s",now->data->country);
    strcat(passCountry,"->");
    strcat(passCountry,now->data->country);
    printf("Passed country =%s\n\n", passCountry);
    (*current)->totalValue = totalDistance;
    (*current)->totalCountry = passCountry;
    //*current= end;
    return *current;
  }
  else if (end == NULL){
    // Throw exception here ...
    Throw(createException("No ending point",END_ERROR));
    *current = NULL;
    return *current;
  }
  else{
    if((*current) != NULL)
    {
      if((*current)->right != NULL && (*current)->left == NULL)
      {
        previous = *current;
        //printf("previous =%s\n", (previous)->data->country);
        if(backtrack==1)
        {
        strcat(passCountry,"->");
        }
        strcat(passCountry,previous->data->country);
        now = (*current)->right;
        //printf("now = %s\n", (now)->data->country);
        totalDistance = totalDistance + findDistance((*current),(*current)->right);
        backtrack=1;
        Asearch(&(*current)->right,end,backtrack,totalDistance);
      }
      else if ((*current)->left != NULL && (*current)->right == NULL)
      {
        previous = *current;
        //printf("previous =%s\n", (previous)->data->country);
        if(backtrack==1)
        {
        strcat(passCountry,"->");
        }
        strcat(passCountry,previous->data->country);
        now = (*current)->left;
        //printf("now = %s\n", (now)->data->country);
        totalDistance = totalDistance + findDistance((*current),(*current)->left);
        backtrack=1;
        Asearch(&(*current)->left,end,backtrack,totalDistance);
      }
      /*
      * If the next left and right node are NULL , it will be force back to the previous node and
      * take other route to continue the journey.
      */
      else if ((*current)->left == NULL && (*current)->right == NULL)
      {
        if((previous)->left == now)
        {
          if(went == NULL)
          {
            totalDistance = totalDistance - findDistance((previous)->left,previous);
            totalDistance = totalDistance + findDistance((previous)->right,previous);
            //printf("backtrack distance :%f\n",totalDistance );
            went = now;
            now = (previous)->right;
            //printf("backtrack now = %s\n", (now)->data->country);
            backtrack=1;
            Asearch(&(previous)->right,end,backtrack,totalDistance);
          }
          else
          {
            went = NULL;
            now = (previous);
            backtrack=1;
            Asearch(&(previous),end,backtrack,totalDistance);
          }

        }
        else if((previous)->right == now)
        {
          if(went == NULL)
          {
            totalDistance = totalDistance - findDistance((previous)->right,previous);
            totalDistance = totalDistance + findDistance((previous)->left,previous);
            //printf("backtrack distance :%f\n",totalDistance );
            went = now;
            now = (previous)->left;
            //printf("backtrack now = %s\n", (now)->data->country);
            backtrack=1;
            Asearch(&(previous)->left,end,backtrack,totalDistance);
          }
          else
          {
            went = NULL;
            now = (previous);
            backtrack=1;
            Asearch(&(previous),end,backtrack,totalDistance);
          }
        }
      }
      else
      {
        if(backtrack == 1)
        {
          // Need to ignore the calculation and start back track again
        }
        else
        {
        temp1 = findDistance((*current)->left,end);
        temp2 = findDistance((*current)->right,end);

        // if temp 2 is bigger means that it will be more far from the ending point
        if(temp1 < temp2)
        {
          previous = *current;
          //printf("previous =%s\n", (previous)->data->country);
          if(backtrack==1)
          {
          strcat(passCountry,"->");
          }
          strcat(passCountry,previous->data->country);
          now = (*current)->left;
          //printf("now = %s\n", (now)->data->country);
          totalDistance = totalDistance + findDistance((*current),(*current)->left);
          //printf("distance :%f\n",totalDistance );
          backtrack=1;
          Asearch(&(*current)->left,end,backtrack,totalDistance);
        }
        // if temp 1 is bgger means that it will be more far from the ending point
        else if (temp1 > temp2)
        {
          previous = *current;
          //printf("previous =%s\n", (previous)->data->country);
          if(backtrack==1)
          {
          strcat(passCountry,"->");
          }
          strcat(passCountry,previous->data->country);
          now = (*current)->right;
          //printf("now = %s\n", (now)->data->country);
          totalDistance = totalDistance + findDistance((*current),(*current)->right);
          //printf("distance :%f\n",totalDistance );
          backtrack=1;
          Asearch(&(*current)->right,end,backtrack,totalDistance);
        }
      }
    }
    }
    /*
    * If current = NULL , it need to force back to the previous node and take other route
    * to continue the journey
    */
    else
    {
      if((previous)->left == *current)
      {
        Asearch(&(previous)->right,end,backtrack,totalDistance);
        // Need to do something
      }
      else if((previous)->right == *current)
      {
        Asearch(&(previous)->left,end,backtrack,totalDistance);
        // Need to do something
      }
    }
}
}

void resetGlobalVariable(){
  previous =NULL;
  now=NULL;
  went=NULL;
  passCountry=NULL;
}

// Simple backtrack
/*
Purpose of backtracking :
Whenever the constraints are not met, we stop further generation of sub-trees of that node,
and backtrack to previous node to explore the nodes not yet explored.
In many scenarios, it saves considerable amount of processing time.
*/

/*
  Using avl for sorting , so no need do backtracking anymore.
*/

void createNode(A_Node *node,int x,int y)
{
  node->x = x;
  node->y = y;
}

void createNodeAvl(Node *node,A_Node *data){
    node->left = NULL;
    node->right = NULL;
    node->balanceFactor =0;
    node->data = data;
}

int compareNode(Node *node, Node *refNode,float d_optimal,Node *end)
{
  float currentDistance = findDistance(node,refNode) + findDistance(refNode,end);
  if(currentDistance > d_optimal)
  {
    //nowDistance = currentDistance;
    return 1;
  }
  else if (currentDistance <= d_optimal)
  {
    //nowDistance = currentDistance;
    return -1;
  }
  else
  {
    Throw(createException("Compare Error, no such compare!",COMPARE_ERROR));
  }
}

int _avlAddNode(Node **rootPtr, Node *nodeToAdd,float d_optimal,Node *end)
{
  if((findDistance((*rootPtr),nodeToAdd)+findDistance(nodeToAdd,end)) !=nowDistance)
  {
    avladdNode(&rootPtr,nodeToAdd,d_optimal,end);
  }
  else{

  }
}


/*
  * If the the added node cost are same with the next one ,
  * it's data will be store to the linkedlist of that added node.
*/
