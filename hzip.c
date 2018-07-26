#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Priority.h"
#include <string.h>

int main(int argc, char* argv[]){
	/*
	Priority queue = newPriority();
	char* encodeTbl[257];
	for(int k = 0; k < 257; k++){
		encodeTbl[k] = malloc(strlen("") + 1);
		strcpy(encodeTbl[k], "");
	}
	Node a = newNode('a', 100);
	Node b = newNode('b', 20);
	Node c = newNode('c', 70);
	Node d = newNode('d', 200);

	add(queue, a);
	add(queue, b);
	add(queue, c);
	add(queue, d);
	printPriority(queue);

	while(getSize(queue) > 1){
		printf("\n");
		Node l = del(queue);
		Node r = del(queue);
		int sum = (getFreq(l)) + (getFreq(r));
		Node tree = newNode(getChar(l), sum);
		setLeft(tree, l);
		setRight(tree, r);
		add(queue, tree);
		printPriority(queue);
	}
	printf("\n");
	Node first = del(queue);
	char path[100];
	strcpy(path, "");
	inOrderTreeWalk(first, path, encodeTbl);
	printf("\n");
	int i;
	
	for(i = 0; i < 257; i++){
		if(strcmp(encodeTbl[i], "") != 0){
			char cchar = i;
			printf("%c %s\n", cchar, encodeTbl[i]);
		}
	}*/

	char* flag;
	FILE* in;
	FILE* out;
	flag = calloc(256, sizeof(char));

	//Check to see how many arguments there are in the commandline

	//If there are less than two arguments, then no flags or files have been
	//given. Thus, we need to show the user how to correctly use the program
	if(argc < 2){
		printf("Too few arguments. Usage: -[flag] in {out}\n");
		exit(EXIT_FAILURE);
	}

	flag = argv[1];

	if(argc == 3){
		//May need to be modified if we are writing bits
		out = fopen(argv[3], "w");
	}

	if(flag[1] != 't' && flag[1] != 'u' && flag[1] != 'c'){
		printf("The flag %s does not exist.", flag);
		exit(EXIT_FAILURE);
	}

	int freqTbl[257]; //EOF will have a value of 256
	char* encodeTbl[257];
	for(int c = 0; c < 257; c++){
		encodeTbl[c] = malloc(strlen("") + 1);
		strcpy(encodeTbl[c], "");
	}

	if(flag[1] != 'u'){
		int fchar;
		//Open the input file regularly; we do not need to read in bits
		in = fopen(argv[2], "r");
		//We may want to print out and create the frequency table for the input file
		for(int n = 0; n < 257; n++){
			freqTbl[n] = 0;
		}
		//Creating character frequency table
		while(1){
			char cahr = fgetc(in);
			if(feof(in))
				break;
			fchar = cahr;
			freqTbl[fchar]++;
		}

		//We need to create a priority queue to build the encoding tree itself,
		//using the characters found in the frequency table as a reference
		//for which characters are included in the file
		Priority queue = newPriority();
		int i;

		for(i = 0; i < 257; i++){
			short c;
			if(freqTbl[i] > 0) {
				c = i;
				add(queue, newNode(c, freqTbl[i]));
			}
		}

		//Now we take each top 2 nodes in the queue and combine them 
		//to create a larger tree; top node is left subtree, second top is
		//the right subtree
		while(getSize(queue) > 1){
			Node left = del(queue);
			Node right = del(queue);
			int sum = getFreq(left) + getFreq(right);
			Node parent = newNode(getChar(left), sum);
			setLeft(parent, left);
			setRight(parent, right);
			add(queue, parent);
		}
		//Once there is only one node in the queue, then we
		//have now created the encoding tree
		Node encodeTree = del(queue);

		//Now we need to grab the codes from the tree for each character;
		//starting from the root and going to the left is the code '0',
		//going to the right is '1'.
		char prefix[100];
		strcpy(prefix, "");

		//Perform a tree walk to store the coded values for each byte
		inOrderTreeWalk(encodeTree, prefix, encodeTbl);
		printf("Completed treewalk\n");
		printf("\n");

		//If the flag is '-t', then display the frequency table of the file's
		//bytes, in ascii character representation
		if(flag[1] == 't'){
			printf("Here is the character frequency table for file %s\n", argv[2]);
			for (i = 0; i < 257; i++){
				if(freqTbl[i] == 0) {
					continue;
				}
				//add if here for # 256 (EOF)
				char curr = i;
				printf(" %c    %d     %s\n", curr, freqTbl[i], encodeTbl[i]);
			}
		} else if(flag[1] == 'c') { //else, write to a compressed file
			//We need to have a second file to contain the compressed version
			//of the original file
			if(argc < 3){
				printf("Error: the program needs a file destination\n");
				exit(EXIT_FAILURE);
			}
			//Now we need to do a post order traversal of the tree in order
			//to retrieve the encoded string of chars

		}
	}

}
