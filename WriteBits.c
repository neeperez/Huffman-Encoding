#include "WriteBits.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct WriteBitsObj {
	int bitIndex;
	char currentByte;
	FILE* myFile;
} WriteBitsObj;

WriteBits newWriteBits(FILE* file){
	WriteBits WB = NULL;
	WB = malloc(sizeof(WriteBitsObj));
	WB->bitIndex = 7;
	WB->currentByte = '\0';
	WB->myFile = file;
	return WB;
}

void clearByte(WriteBits WB){
	WB->bitIndex = 7;
	WB->currentByte = '\0';
}

void flushByte(WriteBits WB){
	if(WB->bitIndex != 7){
		fwrite(&WB->currentByte, sizeof(char), 1, WB->myFile);
		WB->bitIndex = 7;
		WB->currentByte = '\0';
	}
}

void writeBit(WriteBits WB, int bit){
	WB->currentByte |= (bit << WB->bitIndex);
	WB->bitIndex -= 1;
	if(WB->bitIndex == -1){
		printf("Bit index is 0\n");
		flushByte(WB);
	}
}