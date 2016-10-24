#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char * argv[]){

int rank, size;
int prev, next, i;
float my_num, result;
int root = 0;
float rec_buf[2];
int count = 1;
int tag_1 = 1;
int tag_2 = 2;

MPI_Request request[4];
MPI_Status stats[4];

MPI_Init(&argc, &argv);

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

prev = rank - 1;
next = rank + 1;

my_num = rank * rank;

if (rank == 0){
prev = MPI_PROC_NULL;
}

if (rank == (size - 1)){
next = MPI_PROC_NULL;
}
MPI_Irecv(&rec_buf[0], count, MPI_INT, prev, tag_1, MPI_COMM_WORLD, &request[0]);
MPI_Irecv(&rec_buf[1], count, MPI_INT, next, tag_2, MPI_COMM_WORLD, &request[1]);

MPI_Isend(&my_num, count, MPI_INT, prev, tag_2, MPI_COMM_WORLD, &request[2]);
MPI_Isend(&my_num, count, MPI_INT, next, tag_1, MPI_COMM_WORLD, &request[3]);

MPI_Waitall(4, request, stats);

result = (my_num + rec_buf[0] + rec_buf[1])/3.0;

if (rank == 0){
result  = (my_num + rec_buf[1])/2.0;
}

if (rank == (size -1)){
result = (my_num + rec_buf[0])/2.0;
}

printf("Averaged value located at processor %d is %.2f\n", rank, result);

//printf("proc: %d, my_num: %.2f, rec_buf[0]: %.2f rec_buf: %.2f result: %.2f\n", rank, my_num, rec_buf[0], rec_buf[1], result);

//printf("Task %d communicated with tasks %d & %d\n", rank, prev, next);

MPI_Finalize();

}
