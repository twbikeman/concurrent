.PHONY: test
CC=gcc
CFLAGS=-std=c89
main: main.c merge
	$(CC) $(CFLAGS) -o main main.c -std=c89
merge: merge.c
	$(CC) $(CFLAGS) -o merge merge.c -std=c89

test:
	./main < input-file
