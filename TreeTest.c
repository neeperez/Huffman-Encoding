#include <stdio.h>
#include "Tree.h"

int main(){
	Node myNode = newNode('a', 100);
	Node leftNode = newNode('b', 20);
	Node rightNode = newNode('c', 30);

	setLeft(myNode, leftNode);

	setRight(myNode, rightNode);
	char path[100];
	strcpy(path, "");
	printf("%s\n", path);
	inOrderTreeWalk(myNode, path);
	printf("\n");
	postOrderTreeWalk(myNode);

	/*Node biggerNode = newNode('d', 200);
	setLeft(biggerNode, myNode);
	inOrderTreeWalk(biggerNode);
	printf("\n");*/

	return 1;
}