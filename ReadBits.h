#ifndef _READBITS_H_INCLUDE
#define _READBITS_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>

typedef struct ReadBitsObj* ReadBits;

ReadBits newReadBits(FILE* file);
int nextBit(ReadBits RB);
int fileEnd(ReadBits RB);
char currByte(ReadBits RB);

#endif