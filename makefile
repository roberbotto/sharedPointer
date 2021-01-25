CC = g++
CFLAGS = -Wall -std=c++11

main: main.o lib/SharedPointer.o
	$(CC) $(CFLAGS) -o main main.o lib/SharedPointer.o

main.o: main.cpp lib/SharedPointer.h
	$(CC) $(CFLAGS) -c main.cpp

SharedPointer.o: lib/SharedPointer.h
