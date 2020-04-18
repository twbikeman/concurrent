.PHONY: test
CC=gcc
main: main.c merge
	$(CC) -o main main.c -std=c89
merge: merge.c
	$(CC) -o merge merge.c -std=c89

test:
	./main < input-file
