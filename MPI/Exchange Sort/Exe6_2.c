
#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]){
  int size, rank;
  int Prior_Proc, Post_Proc;
  int i;
  double send_buf, recv_buf;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  // Initialize each process with a random number
  srand(time(NULL) * rank);
  send_buf = rand();
  // Initialize the number of stages , Max to go is P/2
  int stage_count = 0;

  // Handle the edges
  if(rank == 0)
    Prior_Proc = MPI_PROC_NULL;
  else
    Prior_Proc = rank - 1;

  if(rank == size - 1)
    Post_Proc = MPI_PROC_NULL;
  else
    Post_Proc = rank + 1;


  while(stage_count <= size/2){
    //Even Stage
    recv_buf = send_buf; 
    if(stage_count % 2 == 0){
      //Even - Odd share.. Even keeps the min, Odd keeps the max
      if(rank % 2 == 0){
        MPI_Send(&send_buf,1,MPI_DOUBLE,Post_Proc,1,MPI_COMM_WORLD);
        MPI_Recv(&recv_buf,1,MPI_DOUBLE,Post_Proc, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        send_buf = (send_buf < recv_buf) ? send_buf: recv_buf;
      }
      else{
        MPI_Recv(&recv_buf,1,MPI_DOUBLE,Prior_Proc, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&send_buf,1,MPI_DOUBLE,Prior_Proc,2,MPI_COMM_WORLD);
        send_buf = (send_buf > recv_buf) ? send_buf: recv_buf;
      }
    }
    // Odd Stage
    else{
      // Odd - Even Share.. Odd keeps the min, Even keeps the max
      if(rank % 2 != 0){
        MPI_Send(&send_buf,1,MPI_DOUBLE,Post_Proc,3,MPI_COMM_WORLD);
        MPI_Recv(&recv_buf,1,MPI_DOUBLE,Post_Proc, 4, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        send_buf = (send_buf < recv_buf) ? send_buf: recv_buf;
      }
      else{
        MPI_Recv(&recv_buf,1,MPI_DOUBLE,Prior_Proc, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&send_buf,1,MPI_DOUBLE,Prior_Proc,4,MPI_COMM_WORLD);
        send_buf = (send_buf > recv_buf) ? send_buf: recv_buf;
      }
    }
    // Update Stage count
    stage_count++;
  }

int root = 0;
double *sortedArr = (double*)malloc(size * sizeof(double));
MPI_Gather(&send_buf, 1, MPI_DOUBLE, sortedArr, 1, MPI_DOUBLE, root, MPI_COMM_WORLD); 

if (rank == root){
  for(i=0; i<size; i++){
    printf("%.1f ", sortedArr[i]);
  }
  printf("\n");
}


  MPI_Finalize();
}
