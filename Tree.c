#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tree.h"

/*--------NODE STUFF---------*/

//Define the node structure
typedef struct NodeObj{
	short character; //The character needs to be represented as a short;
					 //This is because we need to know when there is an eof
					 //which will be represented by 256, a number that needs
					 //9 bits for representation
	struct NodeObj* parent;
	struct NodeObj* left;
	struct NodeObj* right;
	int frequency;
} NodeObj;


Node newNode(short data, int freq){
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

void postOrderTreeWalk(Node N, char* c_code, char* t_code){
	if(N == NULL){
		return;
	}

	postOrderTreeWalk(N->left, c_code, t_code);
	postOrderTreeWalk(N->right, c_code, t_code);
	//IF the node is a leaf, then add 1 to the end of the tree code
	//and continue the traversal
	if(!isLeaf(N)){
		//Hopefully this keeps changes 
		strcat(t_code, "1");
		printf("Not a leaf\n");
		printf("%s\n", t_code);
	} else {
		//Since the node is not a leaf, we need to concat the first 
		//8 bits of the short to the c_code
		strcat(t_code, "0");
		int zero = 1;
		char byte[9];
		int opposite = 0; 
		for(int i = 7; i >= 0; i--){
			int curr_bit = (N->character & (1 << i)) >> i;
			if(curr_bit == 1){
				zero = 0;
			}
			char c_bit = curr_bit + 48; //So we get the ascii rep of the bit
			byte[opposite] = c_bit;
			opposite++;
		}
		//If the byte was all 0s, then we need to distinguish between
		//null and EOF
		if(zero == 1){
			int bit_nine = (N->character & (1 << 8)) >> 8;
			printf("%d\n", bit_nine);
			printf("%s\n", byte);
			//1 to indicate EOF, 0 to indicate null
			if(bit_nine == 1){
				strcat(byte, "1");
			} else {
				strcat(byte, "0");
			}
			printf("%s\n", byte);
		}
		//Clear current char code, add byte to c_code,
		//add c_code to the end of the t_code, and 
		strcpy(c_code, "");
		strcpy(c_code, byte);
		strcat(t_code, c_code);
		printf("%s\n", t_code);
	}
}

Node getLeft(Node N){
	return N->left;
}

Node getRight(Node N){
	return N->right;
}

short getChar(Node N){
	return N->character;
}

int getFreq(Node N){
	return N->frequency;
}