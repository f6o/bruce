CC = gcc
CFLAGS = -g

queue.o: queue.h queue.c
	$(CC) $(CFLAGS) -c -o queue.o queue.c

main: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c
	$(CC) $(CGLAGS) -o main queue.o main.o

clean:
	rm -f queue.o main.o main
