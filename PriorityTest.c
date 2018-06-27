#include "Priority.h"

int main(){
	Priority P = newPriority();
	add(P, 'a', 100);
	printPriority(P);
	printf("\n");
	add(P, 'b', 20);
	add(P, 'c', 70);
	add(P, 'd', 200);
	add(P, 'e', 10);
	printPriority(P);
	printf("\n");
}