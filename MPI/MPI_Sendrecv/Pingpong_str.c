#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define n 50

int main(int argc, char *argv[]){

char pp_ball_s1[n]= "Hello, I'm PP_ball 1!";
char pp_ball_r1[n];
char pp_ball_s2[n] = "Hello, I'm PP_ball 2!";
char pp_ball_r2[n];

int count = n;
int rank;
int tag = 1;
int i;
double start_time, end_time, diff_time;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

start_time = MPI_Wtime();

if (rank == 0){
//count = n;
MPI_Send (&pp_ball_s1, count, MPI_CHAR, 20, tag, MPI_COMM_WORLD);
MPI_Recv (&pp_ball_r1, count, MPI_CHAR, 20, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("%d sucessfully sent %s  and recieved %s\n", rank, pp_ball_s1, pp_ball_r1);
}
else if(rank == 20){
//count = strlen(pp_ball_s2 +1);
MPI_Send (&pp_ball_s2, count, MPI_CHAR, 0, tag, MPI_COMM_WORLD);
MPI_Recv (&pp_ball_r2, count, MPI_CHAR, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("%d successfully sent %s and recieved %s \n",rank, pp_ball_s2, pp_ball_r2);
}

end_time = MPI_Wtime();

if(rank == 0){
diff_time = end_time - start_time;
printf("Timing: %f sec\n", diff_time);
}

MPI_Finalize();

}





