BASE_SOURCES = Tree.c Priority.c Stack.c WriteBits.c ReadBits.c
BASE_OBJECTS = Tree.o Priority.o Stack.o WriteBits.o ReadBits.o
HEADERS      = Tree.h Priority.h Stack.h WriteBits.h ReadBits.h
COMPILE      = gcc -c -g -std=c99 -Wall
LINK         = gcc -o
REMOVE       = rm -f
MEMCHECK     = valgrind --leak-check=full

FileStreamTest: FileStreamTest.o WriteBits.o ReadBits.o
	$(LINK) FileStreamTest FileStreamTest.o WriteBits.o ReadBits.o

FileStreamTest.o: FileStreamTest.c WriteBits.h ReadBits.h
	$(COMPILE) FileStreamTest.c

TreeTest: TreeTest.o Tree.o
	$(LINK) TreeTest TreeTest.o Tree.o

TreeTest.o: TreeTest.c Tree.h
	$(COMPILE) TreeTest.c

$(BASE_OBJECTS): $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES) $(COMPILE) hzip.c

$(BASE_OBJECTS): $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

#Priority.o: Priority.c 
#	gcc -c -g -std=c99 -Wall Priority.c

hzip: hzip.o $(BASE_OBJECTS)
	$(LINK) hzip hzip.o $(BASE_OBJECTS)

hzip.o: $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) hzip.c

PriorityTest: PriorityTest.o Priority.o
	gcc -o PriorityTest PriorityTest.o Priority.o

PriorityTest.o: Priority.c Priority.h
	gcc -c -g -std=c99 -Wall PriorityTest.c

StackTest: StackTest.o Stack.o Tree.o
	$(LINK) StackTest StackTest.o Stack.o Tree.o

StackTest.o: Stack.c Stack.h Tree.h
	$(COMPILE) StackTest.c

clean:
	rm -f FileStreamTest FileStreamTest.o ReadBits.o WriteBits.o StackTest StackTest.o Stack.o TreeTest TreeTest.o Tree.o PriorityTest PriorityTest.o Priority hzip hzip.o
