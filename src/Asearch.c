#include "Asearch.h"
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "nodehelper.h"

float findDistance(A_Node *current, A_Node *end){
  float heuristic;
  heuristic = sqrt ( ((current->x - end->x)*(current->x - end->x)) + ((current->y - end->y)*(current->y - end->y)) );
  printf("%f\n",heuristic);
  return heuristic;
}

void testDistance(A_Node **current, A_Node *end){
  float temp1,temp2;
  temp1 = findDistance((*current)->left,end);
  temp2 = findDistance((*current)->right,end);
}

A_Node *Asearch(A_Node **current, A_Node *end){
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
    if((*current)->left == NULL)
    {
     temp1 = findDistance((*current)->right,end);
     Asearch(&(*current)->right,end);
    }
    else if ((*current)->right == NULL)
    {
      temp1 = findDistance((*current)->left,end);
      Asearch(&(*current)->left,end);
    }
    else{
  temp1 = findDistance((*current)->left,end);
  temp2 = findDistance((*current)->right,end);

  // if temp 2 is bigger means that it will be more far from the ending point
  if(temp1 < temp2)
  {
    Asearch(&(*current)->left,end);
  }
  // if temp 1 is bgger means that it will be more far from the ending point
  else if (temp1 > temp2)
  {
    Asearch(&(*current)->right,end);
  }
}
}
}
