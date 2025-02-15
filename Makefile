CC = gcc
CFLAGS = -Wall -pthread

all: matrix_multiplication

matrix_multiplication: matrix_multiplication.c
	$(CC) $(CFLAGS) matrix_multiplication.c -o matrix_multiplication

clean:
	rm -f matrix_multiplication