#ifndef _PRIORITY_H_INCLUDE
#include "Tree.h"
#define _PRIORITY_H_INCLUDE

typedef struct PriorityObj* Priority;
typedef struct RecordObj* Record;

Priority newPriority();
Record newRecord(Node N);
char getData(Record R);
int getRank(Record  R);

void add(Priority P, Node N);
/*void addNode(Priority P, Node N);*/
Node del(Priority P);
void printPriority(Priority P);
int getSize(Priority P);

#endif