#ifndef _WRITEBITS_H_INCLUDE
#define _WRITEBITS_H_INCLUDE

#include <stdlib.h>
#include <stdio.h>

typedef struct WriteBitsObj* WriteBits;

WriteBits newWriteBits(FILE* file);
void clearByte(WriteBits WB);
void flushByte(WriteBits WB);
void writeBit(WriteBits WB, int bit);



#endif