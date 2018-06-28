#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tree.h"

/*--------NODE STUFF---------*/

//Define the node structure
typedef struct NodeObj{
	char character;
	struct NodeObj* parent;
	struct NodeObj* left;
	struct NodeObj* right;
	int frequency;
} NodeObj;


Node newNode(char data, int freq){
	Node N = NULL;
	N = malloc(sizeof(NodeObj));
	N->character = data;
	N->frequency = freq;
	N->parent = NULL;
	N->left = NULL;
	N->right = NULL;
	return N;
}


int isLeaf(Node N){
	return N->left == NULL && N->right == NULL;
}

void freeNode(Node* ptr){
	if(ptr != NULL && *ptr != NULL){
		free(*ptr);
		*ptr = NULL;
	}
}


void setLeft(Node N, Node L){
	N->left = L;
}

void setRight(Node N, Node R){
	N->right = R;
}

void inOrderTreeWalk(Node N){
	if(N == NULL){
		return;
	}
	inOrderTreeWalk(N->left);
	if(isLeaf(N))
		printf("[%c, %d] ", N->character, N->frequency);
	inOrderTreeWalk(N->right);
}

void postOrderTreeWalk(Node N){
	if(N == NULL){
		return;
	}
	postOrderTreeWalk(N->left);
	postOrderTreeWalk(N->right);
	printf("[%c, %d] ", N->character, N->frequency);
}

Node getLeft(Node N){
	return N->left;
}

Node getRight(Node N){
	return N->right;
}

char getChar(Node N){
	return N->character;
}

int getFreq(Node N){
	return N->frequency;
}