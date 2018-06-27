TreeTest: TreeTest.o Tree.o
	gcc -o TreeTest TreeTest.o Tree.o

TreeTest.o: TreeTest.c Tree.h
	gcc -c -g -std=c99 -Wall TreeTest.c

Tree.o: Tree.c Tree.h
	gcc -c -g -std=c99 -Wall Tree.c

Priority.o: Priority.c Priority.h
	gcc -c -g -std=c99 -Wall Priority.c

PriorityTest: PriorityTest.o Priority.o
	gcc -o PriorityTest PriorityTest.o Priority.o

PriorityTest.o: Priority.c Priority.h
	gcc -c -g -std=c99 -Wall PriorityTest.c

clean:
	rm -f TreeTest TreeTest.o Tree.o PriorityTest PriorityTest.o Priority
