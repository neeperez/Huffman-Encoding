#ifndef _STACK_H_INCLUDE
#include "Tree.h"
#define _STACK_H_INCLUDE

typedef struct StackObj* Stack;
typedef struct StackNodeObj* StackNode;
Stack newStack();
//delete method here

StackNode newStackNode(Node N);
void setNext(StackNode this, StackNode SN);

void push(Stack S, Node N);
Node pop(Stack S);
int isEmpty(Stack S);
void printStack(Stack S);
int getStackSize(Stack S);
#endif