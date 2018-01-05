#ifndef _ASEARCH_H
#define _ASEARCH_H

#include <stdlib.h>
#include "Node.h"
#include "nodehelper.h"

float findDistance(A_Node *current, A_Node *end);
A_Node* Asearch(A_Node **current, A_Node *end);
void testDistance(A_Node **current, A_Node *end);


#endif // _ASEARCH_H
