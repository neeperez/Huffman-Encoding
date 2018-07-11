#include <stdio.h>
#include <stdlib.h>
#include "WriteBits.h"

int main(int argc, char* argv[]){
	FILE* in;
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
	return 1;

}