#ifndef _ASEARCH_H
#define _ASEARCH_H

#include <stdlib.h>
#include "Node.h"
#include "nodehelper.h"
#include <stdio.h>
#include <string.h>
#include "Exception.h"
#include "CException.h"
#include "addnode.h"
#include "avlcompare.h"
#include "removenode.h"
#include "rotate.h"

#define END_ERROR 1
#define avladdNode(root,nodeToAdd,d_optimal)  addNode(root,nodeToAdd,(compare)compareNode,d_optimal)


float findDistance(Node *current, Node *end);
Node* Asearch(Node **current, Node *end,int backtrack,float totalDistance);
void testDistance(A_Node **current, A_Node *end);
void resetGlobalVariable();
void createNodeAvl(Node *node,A_Node *data);
void createNode(A_Node *node,int x,int y);
int compareNode(A_Node *node, Node *refNode,float d_ideal);


#endif // _ASEARCH_H
