#include <stdio.h>
#include <stdlib.h>
#include "Priority.h"

typedef struct RecordObj {
	int rank;
	char data;
	struct RecordObj* next;
} RecordObj;

Record newRecord(char c, int i){
	Record R = NULL;
	R = malloc(sizeof(RecordObj));
	R->rank = i;
	R->data = c;
	R->next = NULL;
	return R;
}

typedef struct PriorityObj{
	int empty;
	struct RecordObj* head;
} PriorityObj;

Priority newPriority(){
	Priority P = NULL;
	P = malloc(sizeof(PriorityObj));
	P->empty = 1;
	P->head = NULL;
	return P;
}

void add(Priority P, char c, int i){
	Record R = newRecord(c, i);
	if (P->empty == 1){
		P->head = R;
		P->empty = 0;
		return;
	}
	if(P->head->rank < i){
		Record temp = P->head;
		P->head = R;
		R->next = temp;
		return;
	}
	Record curr = P->head->next;
	Record prev = P->head;
	while(curr != NULL){
		if(curr->rank < i){
			Record temp = curr;
			prev->next = R;
			R->next = temp;
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	prev->next = R;
}

Record del(Priority P){
	if(P->empty == 1){
		printf("Called delete on an empty Priority\n");
		return NULL;
	}
	Record temp = P->head;
	P->head = P->head->next;
	return temp;
}

void printPriority(Priority P){
	Record curr = P->head;
	while(curr != NULL){
		printf("(%c, %d) ", curr->data, curr->rank);
		curr = curr->next;
	}
}