#include "nodehelper.h"

extern Node node1,node5,node10,node15,node20,node25,node30,node35,node40;
extern Node node45,node50,node55,node70;
extern Node node100;
extern Node node60,node65,node75,node80,node85,node90,node95;

extern StringNode nodeCristiano,nodeMessi,nodeVanPersie,nodeRooney,nodeDeGea;
extern A_Node nodeJohor,nodeMelaka,nodePenang,nodeSabah,nodeSarawak;

void initN(A_Node *node,int x,int y,A_Node *left,A_Node *right)
{
  node->x = x;
  node->y = y;
  node->left = left;
  node->right = right;
}

void initNode(Node *node,Node *left,Node *right, int bf)
{
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}

void initStringNode(StringNode *node,StringNode *left,StringNode *right, int bf)
{
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}

void initNnode(void){
  nodeJohor.country = "Johor";
  nodeMelaka.country = "Melaka";
  nodePenang.country = "Penang";
  nodeSabah.country = "Sabah";
  nodeSarawak.country = "Sarawak";
}

void initStrData(void){
  nodeCristiano.data = "Cristiano";
  nodeMessi.data = "Messi";
  nodeVanPersie.data = "VanPersie";
  nodeRooney.data ="Rooney";
  nodeDeGea.data = "DeGea";
}
