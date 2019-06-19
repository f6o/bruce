CC = gcc
CFLAGS = -g

queue.o: queue.h queue.c
	$(CC) $(CFLAGS) -c queue.c -o queue.o

main: main.c
	$(CC) $(CFLAGS) main.c -o main

clean:
	rm -f queue.o main
