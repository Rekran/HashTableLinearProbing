CC = g++

all:
	$(CC) Node.cpp HashTable.cpp main.cpp -o main

clean:
	rm cgprog
