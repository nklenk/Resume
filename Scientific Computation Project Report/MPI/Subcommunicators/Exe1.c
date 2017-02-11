#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char * argv[]){

int i;
int rank, size;
int my_rank;
MPI_Init(&argc, &argv);

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

int my_row = floor(rank/4);
int my_col = rank % 4;

MPI_Comm row_comm;
MPI_Comm_split(MPI_COMM_WORLD, my_row, my_rank, &row_comm);//floor may need float
MPI_Bcast(&my_row, 1, MPI_INT, 0, row_comm);//through all of the rows

MPI_Comm col_comm;
MPI_Comm_split(MPI_COMM_WORLD, my_col, my_rank, &col_comm);
MPI_Bcast(&my_col, 1, MPI_INT, 0, col_comm); //through all of the columns

printf("Rank: %d, col: %d, row: %d\n", rank, my_col, my_row);
MPI_Comm_free(&row_comm);
MPI_Comm_free(&col_comm);

MPI_Finalize();
}


