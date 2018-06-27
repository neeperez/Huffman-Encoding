#ifndef _TREE_H_INCLUDE
#define _TREE_H_INCLUDE

typedef struct TreeObj* Tree;
typedef struct NodeObj* Node;

//-----Node Functions-----
Node newNode(char data);
void freeNode(Node* ptr);
int isLeaf(Node N);
void printNode(Node N);

//-----Tree Functions-----
Tree newTree(char data);
void freeTree(Tree* ptr);
void insertLeft(Tree T,char left);
void insertRight(Tree T, char right);
void inOrderTreeWalk(Tree T);
void postOrderTreeWalk(Tree T);
Node* getLeft(Tree T);
Node* getRight(Tree T);
void printTree(Tree T);

#endif