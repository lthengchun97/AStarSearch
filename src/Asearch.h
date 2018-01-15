#ifndef _ASEARCH_H
#define _ASEARCH_H

#include <stdlib.h>
#include "Node.h"
#include "nodehelper.h"
#include <stdio.h>
#include <string.h>
#include "Exception.h"
#include "CException.h"

#define END_ERROR 1

float findDistance(A_Node *current, A_Node *end);
A_Node* Asearch(A_Node **current, A_Node *end,int backtrack,float totalDistance);
void testDistance(A_Node **current, A_Node *end);
void resetGlobalVariable();

#endif // _ASEARCH_H
