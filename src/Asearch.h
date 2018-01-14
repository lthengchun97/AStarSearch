#ifndef _ASEARCH_H
#define _ASEARCH_H

#include <stdlib.h>
#include "Node.h"
#include "nodehelper.h"
#include <stdio.h>
#include <string.h>

float findDistance(A_Node *current, A_Node *end);
A_Node* Asearch(A_Node **current, A_Node *end,float longest);
void testDistance(A_Node **current, A_Node *end);


#endif // _ASEARCH_H
