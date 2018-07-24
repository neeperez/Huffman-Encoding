#include <stdio.h>
#include <stdlib.h>
#include "ReadBits.h"

typedef struct ReadBitsObj{
	int bitIndex;
	FILE* myFile;
	char byte;
	int isEOF;
} ReadBitsObj;

ReadBits newReadBits(FILE* file){
	ReadBits rB = NULL;
	rB = malloc(sizeof(ReadBitsObj));
	rB->bitIndex = 0;
	rB->myFile = file;
	rB->byte = '\0';
	rB->isEOF = 0;
	return rB;
}

int nextBit(ReadBits RB){
	if(RB->bitIndex == 0){
		if(fread(&RB->byte, sizeof(char), 1, RB->myFile) != 1){
			RB->isEOF = 1;
			return -1;
		}
		RB->bitIndex = 8;
	}
	RB->bitIndex -= 1;
	int currBit = (RB->byte & (1 << RB->bitIndex)) >> RB->bitIndex;
	return currBit;
}

int fileEnd(ReadBits RB){
	char buffer;
	return RB->isEOF;
}

char currByte(ReadBits RB){
	return RB->byte;
}