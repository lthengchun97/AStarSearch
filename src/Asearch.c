#include "Asearch.h"
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "nodehelper.h"

// The follow previous and now node will be set as global variable.
A_Node *previous,*now,*went;

float findDistance(A_Node *current, A_Node *end){
  float heuristic;
  heuristic = sqrt ( ((current->x - end->x)*(current->x - end->x)) + ((current->y - end->y)*(current->y - end->y)) );
  //printf("%f\n",heuristic);
  return heuristic;
}

void testDistance(A_Node **current, A_Node *end){
  float temp1,temp2;
  temp1 = findDistance((*current)->left,end);
  temp2 = findDistance((*current)->right,end);
}

A_Node *Asearch(A_Node **current, A_Node *end,float longest){
  float temp1,temp2;

  if(*current == end)
  {
    *current = end;
    return *current;
  }
  else if (end == NULL){
    *current = NULL;
    return *current;
  }
  else{
    if((*current) != NULL)
    {
      if((*current)->right != NULL && (*current)->left == NULL)
      {
        previous = *current;
        printf("previous =%s\n", (previous)->country);
        now = (*current)->right;
        printf("now = %s\n", (now)->country);
        temp1 = findDistance((*current)->right,end);
        Asearch(&(*current)->right,end,longest);
      }
      else if ((*current)->left != NULL && (*current)->right == NULL)
      {
        previous = *current;
        printf("previous =%s\n", (previous)->country);
        now = (*current)->left;
        printf("now = %s\n", (now)->country);
        temp1 = findDistance((*current)->left,end);
        Asearch(&(*current)->left,end,longest);
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
            went = now;
            now = (previous)->right;
            Asearch(&(previous)->right,end,longest);
            longest=1;
          }
          else
          {
            went = NULL;
            now = (previous);
            Asearch(&(previous),end,longest);
            longest=1;
          }

        }
        else if((previous)->right == now)
        {
          if(went == NULL)
          {
            went = now;
            now = (previous)->left;
            Asearch(&(previous)->left,end,longest);
            longest=1;
          }
          else
          {
            went = NULL;
            now = (previous);
            Asearch(&(previous),end,longest);
            longest=1;
          }
        }
      }
      else
      {
        if(longest == 1)
        {
          // Need to ignore the calculation and back track
        }
        else
        {
        temp1 = findDistance((*current)->left,end);
        temp2 = findDistance((*current)->right,end);

        // if temp 2 is bigger means that it will be more far from the ending point
        if(temp1 < temp2)
        {
          previous = *current;
          printf("previous =%s\n", (previous)->country);
          now = (*current)->left;
          printf("now = %s\n", (now)->country);
          temp1 = findDistance((*current)->left,end);
          Asearch(&(*current)->left,end,longest);
        }
        // if temp 1 is bgger means that it will be more far from the ending point
        else if (temp1 > temp2)
        {
          previous = *current;
          printf("previous =%s\n", (previous)->country);
          now = (*current)->right;
          printf("now = %s\n", (now)->country);
          temp1 = findDistance((*current)->right,end);
          Asearch(&(*current)->right,end,longest);
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
        Asearch(&(previous)->right,end,longest);
      }
      else if((previous)->right == *current)
      {
        Asearch(&(previous)->left,end,longest);
      }
    }
}
}

// Simple backtrack
/*
Purpose of backtracking :
Whenever the constraints are not met, we stop further generation of sub-trees of that node,
and backtrack to previous node to explore the nodes not yet explored.
In many scenarios, it saves considerable amount of processing time.
*/
