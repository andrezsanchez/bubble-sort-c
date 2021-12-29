CC=clang
all:
	$(CC) main.c -o main -Wall -std=c17
.PHONY: all
