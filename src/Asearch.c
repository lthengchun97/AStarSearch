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



//void Asearch(A_Node current, A_Node end){
//
//}
