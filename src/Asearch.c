#include "Asearch.h"
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "nodehelper.h"

float findDistance(A_Node *current, A_Node *end){
  float heuristic;
  heuristic = sqrt ( ((current->x - end->x)*(current->x - end->x)) + ((current->y - end->y)*(current->y - end->y)) );
  printf("%f",heuristic);
  return heuristic;
}



void Asearch(A_Node **current, A_Node *end){
  float temp1,temp2;
  if(*current== NULL)
  {
    end = *current;
  }
  //else if (end == NULL){
  //  return ;
 //  }
  else{
    if(&(*current)->left == NULL)
    {
      Asearch(&(*current)->right,end);
    }
    else if (&(*current)->right == NULL)
    {
      Asearch(&(*current)->left,end);
    }
    else{
  temp1 = findDistance(&(*current)->left,end);
  temp2 = findDistance(&(*current)->right,end);

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
