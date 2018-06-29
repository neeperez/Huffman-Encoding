#include <stdio.h>
#include <stdlib.h>
#include "Priority.h"
#include "Tree.h"

typedef struct RecordObj {
	int rank;
	char data;
	struct RecordObj* next;
	Node node;
} RecordObj;

Record newRecord(Node N){
	Record R = NULL;
	R = malloc(sizeof(RecordObj));
	R->rank = getFreq(N);
	R->data = getChar(N);
	R->node = N;
	R->next = NULL;
	return R;
}

char getData(Record R){
	return R->data;
}

int getRank(Record R){
	return R->rank;
}

typedef struct PriorityObj{
	int empty;
	int size;
	struct RecordObj* head;
} PriorityObj;

Priority newPriority(){
	Priority P = NULL;
	P = malloc(sizeof(PriorityObj));
	P->empty = 1;
	P->size = 0;
	P->head = NULL;
	return P;
}

void add(Priority P, Node N){
	Record R = newRecord(N);
	if (P->empty == 1){
		P->head = R;
		P->empty = 0;
		P->size = 1;
		return;
	}
	if(P->head->rank > getFreq(N)){
		Record temp = P->head;
		P->head = R;
		R->next = temp;
		P->size++;
		return;
	}
	Record curr = P->head->next;
	Record prev = P->head;
	while(curr != NULL){
		if(curr->rank > getFreq(N)){
			Record temp = curr;
			prev->next = R;
			R->next = temp;
			P->size++;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	prev->next = R;
	P->size++;
}

/*void addNode(Priority P, Node N){
	int c = N->character;
	Record R = newRecord(N->character, N->frequency);
	if (P->empty == 1){
		P->head = R;
		P->empty = 0;
		P->size++;
		return;
	}
	if(P->head->rank < N->frequency){
		Record temp = P->head;
		P->head = R;
		R->next = temp;
		P->size++;
		return;
	}
	Record curr = P->head->next;
	Record prev = P->head;
	while(curr != NULL){
		if(curr->rank < N->frequency){
			Record temp = curr;
			prev->next = R;
			R->next = temp;
			P->size++;
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	P->size++;
	prev->next = R;
}*/

Node del(Priority P){
	if(P->empty == 1){
		printf("Called delete on an empty Priority\n");
		return NULL;
	}
	Record temp = P->head;
	P->head = P->head->next;
	P->size--;
	if(P->head == NULL)
		P->empty = 1;
	return temp->node;
}

int getSize(Priority P){
	return P->size;
}

void printPriority(Priority P){
	Record curr = P->head;
	while(curr != NULL){
		printf("(%c, %d) ", curr->data, curr->rank);
		curr = curr->next;
	}
}