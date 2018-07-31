#ifndef _TREE_H_INCLUDE
#define _TREE_H_INCLUDE

typedef struct NodeObj* Node;

//-----Node Functions-----
Node newNode(short data, int freq);
void freeNode(Node* ptr);
int isLeaf(Node N);

//-----Tree Functions-----
void setLeft(Node N, Node L);
void setRight(Node N, Node R);
void inOrderTreeWalk(Node N, char* prefix, char** tbl);
void postOrderTreeWalk(Node N, char* c_code, char* t_code);
Node getLeft(Node N);
Node getRight(Node N);
short getChar(Node N);
int getFreq(Node N);

#endif