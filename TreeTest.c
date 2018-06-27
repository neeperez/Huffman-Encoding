#include "Tree.h"

int main(){
	Node myNode = newNode('a', 100);
	Node leftNode = newNode('b', 20);
	Node rightNode = newNode('c', 30);
	inOrderTreeWalk(myNode);
	printf("\n");
	setLeft(myNode, leftNode);
	inOrderTreeWalk(myNode);
	printf("\n");
	setRight(myNode, rightNode);
	inOrderTreeWalk(myNode);
	printf("\n");

	Node biggerNode = newNode('d', 200);
	setLeft(biggerNode, myNode);
	inOrderTreeWalk(biggerNode);
	printf("\n");

	return 1;
}