#include "Priority.h"
#include "Tree.h"

int main(){
	Priority P = newPriority();
	Node a = newNode('a', 100);
	Node b = newNode('b', 20);
	Node c = newNode('c', 70);
	Node d = newNode('d', 200);
	Node e = newNode('e', 10);

	add(P, a);
	printPriority(P);
	printf("\n");
	add(P, b);
	add(P, c);
	add(P, d);
	add(P, e);
	printPriority(P);
	printf("\n");
}