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

	if(argc < 2){
		printf("Too few arguments. Usage: -[flag] in {out}\n");
		exit(EXIT_FAILURE);
	}
	flag = argv[1];
	in = fopen(argv[2], "r");
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
	printf("yeyt");

	if(flag[1] != 'u'){
		int fchar;
		printf("Flag is not uncomp.\n");
		//We want to print out and create the frequency table for the input file
		for(int n = 0; n < 257; n++){
			freqTbl[n] = 0;
		}
		while(1){
			char cahr = fgetc(in);
			if(feof(in))
				break;
			printf("%c", cahr);
			fchar = cahr;
			freqTbl[fchar]++;
		}
		printf("\n");
		printf("Created freq. tables\n");
		for(int n = 0; n < 257; n++){
			printf("%d\n", freqTbl[n]);
		}

		Priority queue = newPriority();
		int i;

		for(i = 0; i < 257; i++){
			char c;
			if(freqTbl[i] > 0) {
				c = i;
				add(queue, newNode(c, freqTbl[i]));
			}
		}
		printf("Made priority\n");
		printPriority(queue);
		while(getSize(queue) > 1){
			Node left = del(queue);
			Node right = del(queue);
			int sum = getFreq(left) + getFreq(right);
			Node parent = newNode(getChar(left), sum);
			setLeft(parent, left);
			setRight(parent, right);
			add(queue, parent);
		}
		//Now the queue only has one node: the encoding tree
		Node encodeTree = del(queue);

		printf("Acquired tree\n");
		char prefix[100];
		strcpy(prefix, "");
		inOrderTreeWalk(encodeTree, prefix, encodeTbl);
		printf("Completed treewalk\n");
		printf("\n");
		for (i = 0; i < 257; i++){
			if(freqTbl[i] == 0) {
				continue;
			}
			char curr = i;
			printf(" %c    %d     %s\n", curr, freqTbl[i], encodeTbl[i]);
		}
	}

}
