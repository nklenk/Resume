#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char * argv[]){

int rank;
int size;
int send_count = 1, recv_count = 1;
int send_tag = 1, recv_tag = 1;
int buf_in;
int buf_out;
int dest;
int source;
double start_time, end_time, diff_time;

MPI_Init(&argc, &argv);

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

buf_in = rank;

//source = rank;

start_time = MPI_Wtime();
if (rank != 0){
	source = rank - 1;
}
else{
	source = MPI_PROC_NULL;
}

if (rank != size - 1){
	dest = rank + 1;
}
else{
	dest = MPI_PROC_NULL;
}

MPI_Sendrecv(&buf_in, send_count, MPI_INT, dest, send_tag, &buf_out, recv_count, MPI_INT, source, recv_tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

end_time = MPI_Wtime();
diff_time = end_time - start_time;

if(rank == 1){
printf("Sent from P:%d, recieved by P:%d, message:%d \n", rank, dest, buf_out);
printf("Sent from P:%d, recieved by P:%d, message:%d \n", source, rank, buf_in);

printf("Time: %f\n", diff_time);
}

MPI_Finalize();

}
