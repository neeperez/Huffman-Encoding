#include "Tree.h"
#include "Priority.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	/*
	Priority queue = newPriority();
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
	inOrderTreeWalk(first, path);*/

	char* flag;
	FILE* in;
	FILE* out;
	file = calloc(256, sizeof(char));

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

}
