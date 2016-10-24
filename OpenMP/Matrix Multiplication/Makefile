CC = gcc
CFLAGS = -o
MPFLAGS = -fopenmp

all: MatrixMultiply

MatrixMultiply: MatrixMultiply.c
	$(CC) $(CFLAGS) $@ $^ $(MPFLAGS)
