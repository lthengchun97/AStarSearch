#ifndef _ADDNODE_H
#define _ADDNODE_H

#include <stdio.h>
#include "Node.h"
#include "rotate.h"
#include "avlcompare.h"

typedef int (*compare)(void *data, Node *refNode,float d_ideal);

#define avlAddInteger(r,n)     addNode(r,n,(compare)integerCompare,d_ideal);
#define avlAddString(r,n)      addNode((Node **)r,(Node *)n,(compare)stringCompare,d_ideal);

//Node *addNode(Node **rootPtr, Node *nodeToAdd);
int addNode(Node **rootPtr, Node *nodeToAdd,compare integerCompare, float d_ideal);
//int stringCompare(char* data,Node *refNode);


#endif // _ADDNODE_H
