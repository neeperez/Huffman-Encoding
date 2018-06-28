#include "Tree.h"
#include "Priority.h"
#include <stdio.h>

int main(){
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
	inOrderTreeWalk(first);
}
