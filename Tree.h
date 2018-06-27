#ifndef _TREE_H_INCLUDE
#define _TREE_H_INCLUDE

typedef struct NodeObj* Node;

//-----Node Functions-----
Node newNode(char data, int freq);
void freeNode(Node* ptr);
int isLeaf(Node N);

//-----Tree Functions-----
void setLeft(Node N, Node L);
void setRight(Node N, Node R);
void inOrderTreeWalk(Node N);
void postOrderTreeWalk(Node N);
Node getLeft(Node N);
Node getRight(Node N);

#endif