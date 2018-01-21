#include "addnode.h"
#include <stdlib.h>
#include <stdio.h>
#include "rotate.h"
#include "avlcompare.h"


// add node with considering the height
int addNode(Node **rootPtr, Node *nodeToAdd, compare compareNode, float d_ideal,Node *end){
  int height;
  //int temp = IntCompare((*rootPtr)->data,nodeToAdd);
    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return height=1;
      }
    else{
      int compare1 = compareNode(nodeToAdd,(*rootPtr),d_ideal,end);
      if (compare1 == -1)
      {
      height = addNode(&(*rootPtr)->left,nodeToAdd,(compare)integerCompare,d_ideal,end);
        if(height==1){
        (*rootPtr)->balanceFactor -= 1;
          if((*rootPtr)->balanceFactor==0)
          height=0;
        }
      else
      (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;

      }
      else if (compare1 == 1)
      {
      height =addNode(&(*rootPtr)->right,nodeToAdd,(compare)integerCompare,d_ideal,end);
        if(height==1){
        (*rootPtr)->balanceFactor += 1;
          if((*rootPtr)->balanceFactor==0)
            height=0;
          }
        else
          (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;
      }
    }
    if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTree(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTree(&(*rootPtr));
    else{
       *rootPtr = *rootPtr;
      }
        return height;
 }

/*
//add a new node ( simple mode,without considering the height)
Node *addNode(Node **rootPtr, Node *nodeToAdd)
{

    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return *rootPtr;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
        (*rootPtr)->left = addNode(&(*rootPtr)->left,nodeToAdd);
        (*rootPtr)->balanceFactor -= 1;
      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
        (*rootPtr)->right = addNode(&(*rootPtr)->right,nodeToAdd);
        (*rootPtr)->balanceFactor += 1;
      }
      }

      if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTree(&(*rootPtr));
      else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTree(&(*rootPtr));
      else{
        *rootPtr = *rootPtr;
      }

        return *rootPtr;
 }
*/
