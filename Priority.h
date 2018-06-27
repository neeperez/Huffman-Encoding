#ifndef _PRIORITY_H_INCLUDE
#define _PRIORITY_H_INCLUDE

typedef struct PriorityObj* Priority;
typedef struct RecordObj* Record;

Priority newPriority();
Record newRecord(char c, int i);

void add(Priority P, char c, int i);
Record del(Priority P);
void printPriority(Priority P);

#endif