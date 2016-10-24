#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char *argv[]){

int pp_ball_s1 = 3;
int pp_ball_r1;
int pp_ball_s2 = 4;
int pp_ball_r2;

int count = 1;
int rank;
int tag = 1;
double start_time, end_time, diff_time;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
int partner_rank = rank + 1;

start_time = MPI_Wtime();

if (rank == 0){
MPI_Send (&pp_ball_s1, count, MPI_INT, 1, tag, MPI_COMM_WORLD);
MPI_Recv (&pp_ball_r1, count, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("%d sucessfully sent %d  and recieved %d\n", rank, pp_ball_s1, pp_ball_r1);
}
else if(rank == 1){
partner_rank = 0;
MPI_Send (&pp_ball_s2, count, MPI_INT, 0, tag, MPI_COMM_WORLD);
MPI_Recv (&pp_ball_r2, count, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("%d successfully sent %d and recieved %d \n",rank, pp_ball_s2, pp_ball_r2);
}

end_time = MPI_Wtime();

if(rank == 0){
diff_time = end_time - start_time;
printf("Timing: %f sec\n", diff_time);
}

MPI_Finalize();

}





