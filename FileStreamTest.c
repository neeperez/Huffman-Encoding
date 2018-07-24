#include <stdio.h>
#include <stdlib.h>
#include "WriteBits.h"
#include "ReadBits.h"

int main(int argc, char* argv[]){
	FILE* in;
	FILE* read;
	in = fopen(argv[1], "wb");
	WriteBits myWB = newWriteBits(in);
	writeBit(myWB, 0);
	writeBit(myWB, 1);
	writeBit(myWB, 1);
	writeBit(myWB, 0);
	writeBit(myWB, 0);
	writeBit(myWB, 0);
	writeBit(myWB, 0);
	writeBit(myWB, 1);
	flushByte(myWB);
	fclose(in);

	read = fopen(argv[2], "rb");
	ReadBits myRB = newReadBits(read);
	printf("%d\n", nextBit(myRB));
	printf("%d\n", nextBit(myRB));
	printf("End of file?: %d\n", fileEnd(myRB));
	printf("%d\n", nextBit(myRB));
	printf("%d\n", nextBit(myRB));
	printf("%d\n", nextBit(myRB));
	printf("%d\n", nextBit(myRB));
	printf("%d\n", nextBit(myRB));
	printf("%d\n", nextBit(myRB));
	return 1;

}