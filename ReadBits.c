#include <stdio.h>
#include <stdlib.h>
#include "ReadBits.h"

typedef struct ReadBitsObj{
	int bitIndex;
	FILE* myFile;
	char byte;
} ReadBitsObj;

ReadBits newReadBits(FILE* file){
	ReadBits rB = NULL;
	rB = malloc(sizeof(ReadBitsObj));
	rB->bitIndex = 0;
	rB->myFile = file;
	rB->byte = '\0';
	return rB;
}

int nextBit(ReadBits RB){
	if(RB->bitIndex == 0){
		fread(&RB->byte, sizeof(char), 1, RB->myFile);
		RB->bitIndex = 8;
	}
	RB->bitIndex -= 1;
	int currBit = (RB->byte & (1 << RB->bitIndex)) >> RB->bitIndex;
	return currBit;
}

int fileEnd(ReadBits RB){
	char buffer;
	return (RB->bitIndex == 0 && fread(&buffer, sizeof(char), 1, RB->myFile) != 1);
}

char currByte(ReadBits RB){
	return RB->byte;
}