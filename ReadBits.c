#include <stdio.h>
#include <stdlib.h>
#include "ReadBits.h"

typedef struct ReadBitsObj{
	int bitIndex;
	FILE* myFile;
	char byte;
} ReadBitsObj;

