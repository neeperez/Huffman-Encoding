#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Tree.h"

typedef struct StackObj {
	struct StackNodeObj* top;
	int size;
} StackObj;

typedef struct StackNodeObj {
	Node data;
	struct StackNodeObj* next;
} StackNodeObj;

Stack newStack(){
	Stack S = NULL;
	S = malloc(sizeof(StackObj));
	S->top = NULL;
	S->size = 0;
	return S;
}

StackNode newStackNode(Node N){
	StackNode SN = NULL;
	SN = malloc(sizeof(StackNodeObj));
	SN->data = N;
	SN->next = NULL;
	return SN;
}

void setNext(StackNode this, StackNode SN){
	this->next = SN;
}

void push (Stack S, Node N){
	StackNode temp = S->top;
	S->top = newStackNode(N);
	setNext(S->top, temp);
	S->size++;
}

int isEmpty(Stack S){
	return S->size == 0;
}

Node pop (Stack S) {
	StackNode popped = S->top;
	S->top = S->top->next;
	Node N = popped->data;
	S->size--;
	return N;
}

int getStackSize(Stack S){
	return S->size;
}

void printStack(Stack S){
	StackNode curr = S->top;
	while (curr != NULL){
		printf("{%c, %d} ", getChar(curr->data), getFreq(curr->data));
		curr = curr->next;
	}
	printf("\n");
}

