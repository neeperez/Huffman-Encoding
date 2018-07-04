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

void inOrderTreeWalk(Node N, char* prefix, char** tbl){
	if(N == NULL){
		return;
	}
	char np[256];
	strcpy(np, prefix);
	inOrderTreeWalk(N->left, strcat(np, "0"), tbl);
	if(isLeaf(N)){
		//printf("[%c, %s] ", N->character, prefix);
		int ichar = N->character;
		tbl[ichar] = malloc(strlen(prefix) +1);
		strcpy(tbl[ichar], prefix);
	}
	char pp[256];
	strcpy(pp, prefix);
	inOrderTreeWalk(N->right, strcat(pp, "1"), tbl);
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