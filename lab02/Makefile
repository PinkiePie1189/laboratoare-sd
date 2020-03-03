CC=clang
CFLAGS= -std=c99 -Wall -Wextra -pedantic
DEBUG=-g -ggdb -O0 -march=native

build: TestLinkedList

TestLinkedList: src/TestLinkedList.o src/LinkedList.o
	$(CC) $(CFLAGS) $(DEBUG) src/TestLinkedList.o src/LinkedList.o -o TestLinkedList

src/LinkedList.o: src/LinkedList.h src/LinkedList.c
	$(CC) $(CFLAGS) $(DEBUG) src/LinkedList.c -c -o src/LinkedList.o

src/TestLinkedList.o: src/TestLinkedList.c
	$(CC) $(CFLAGS) $(DEBUG) src/TestLinkedList.c -c -o src/TestLinkedList.o

run:
	./TestLinkedList

clean:
	rm src/*.o
	rm TestLinkedList

