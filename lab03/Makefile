CC=clang
CFLAGS=-Wall -Wextra -pedantic -std=c99
DEBUG=-g -ggdb -O0 -march=native

build: TestCircularDoublyLinkedList

TestCircularDoublyLinkedList: src/TestCircularDoublyLinkedList.o src/CircularDoublyLinkedList.o
	$(CC) $(CFLAGS) $(DEBUG) src/TestCircularDoublyLinkedList.o src/CircularDoublyLinkedList.o -o TestCircularDoublyLinkedList

src/CircularDoublyLinkedList.o: src/CircularDoublyLinkedList.h src/CircularDoublyLinkedList.c
	$(CC) $(CFLAGS) $(DEBUG) src/CircularDoublyLinkedList.c -c -o src/CircularDoublyLinkedList.o

src/TestCircularDoublyLinkedList.o: src/TestCircularDoublyLinkedList.c
	$(CC) $(CFLAGS) $(DEBUG) src/TestCircularDoublyLinkedList.c -c -o src/TestCircularDoublyLinkedList.o

run:
	./TestCircularDoublyLinkedList

clean:
	rm src/*.o
	rm TestCircularDoublyLinkedList

