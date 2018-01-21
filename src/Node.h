#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>


typedef struct Node Node;
typedef struct StringNode StringNode;
typedef struct A_Node A_Node;

struct Node{
  Node *left;                       //Must be a pointer because its pointing to another Node
  Node *right;
  int balanceFactor;
  A_Node *data;
  float totalValue;
  char* totalCountry;
  Node *next;
};


struct StringNode {
  StringNode *left;
  StringNode *right;
  int balanceFactor;
  char *data;
};


struct A_Node {
  int x;
  int y;
  char *country;
  A_Node *left;
  A_Node *right;
  float totalValue;
};

#endif // _NODE_H
