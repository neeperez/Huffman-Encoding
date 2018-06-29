#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Stack.h"

int main(){
	Node a = newNode('a', 100);
	Node b = newNode('b', 300);
	Node c = newNode('c', 400);

	Stack myStack = newStack();
	push(myStack, a);
	push(myStack, b);
	printStack(myStack);

	printf("%d\n", getStackSize(myStack));

	Node n = pop(myStack);
	inOrderTreeWalk(n);
	printf("\n");
	printf("%d\n", getStackSize(myStack));
	printStack(myStack);

	push(myStack, c);

	printStack(myStack);
	printf("%d\n", getStackSize(myStack));
	
	Node e = pop(myStack);
	Node f = pop(myStack);
	printStack(myStack);
	printf("%d\n", getStackSize(myStack));

	printf("%d\n", isEmpty(myStack));
}