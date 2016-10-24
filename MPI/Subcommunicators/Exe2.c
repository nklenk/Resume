#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char * argv[]){

int size, rank;
int my_num, new_num;
int my_sec;
int init_num;
MPI_Init(&argc, &argv);

MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

my_num = rank;

if((rank%4 == 0||rank%4 == 1) && (rank/4 == 0||rank/4 == 1)){
my_sec = 1;
}

else if((rank%4 == 2||rank%4 == 3)&&(rank/4 == 2||rank/4 == 3)){
my_sec = 2;
}

else{ //if((rank%4 == 0 ||rank%4 == 1)&&(rank/4 == 2||rank/4 == 3)){
my_sec = 3;
}

MPI_Comm diag_comm;
MPI_Comm_split(MPI_COMM_WORLD, my_sec, rank, &diag_comm);

int my_rank, my_size;
MPI_Comm_rank(diag_comm, &my_rank);
MPI_Comm_size(diag_comm, &my_size);

if(my_sec == 1 || my_sec == 2){
	if(my_rank == 1){
	MPI_Send(&my_num, 1, MPI_INT, 2, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 2, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 2){
	MPI_Recv(&new_num, 1, MPI_INT, 1, 1, diag_comm, MPI_STATUS_IGNORE);
	MPI_Send(&my_num, 1, MPI_INT, 1, 1, diag_comm);
		init_num = my_num;
		my_num = new_num;
	}
}

if(my_sec ==3){
	if(my_rank == 0){
	MPI_Send(&my_num, 1, MPI_INT, 4, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 4, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 4){
	MPI_Send(&my_num, 1, MPI_INT, 0, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 0, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 1){
	MPI_Send(&my_num, 1, MPI_INT, 6, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 6, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 6){
	MPI_Send(&my_num, 1, MPI_INT, 1, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 1, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 2){
	MPI_Send(&my_num, 1, MPI_INT, 5, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 5, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 5){
	MPI_Send(&my_num, 1, MPI_INT, 2, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 2, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 3){
	MPI_Send(&my_num, 1, MPI_INT, 7, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 7, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
	if(my_rank == 7){
	MPI_Send(&my_num, 1, MPI_INT, 3, 1, diag_comm);
	MPI_Recv(&new_num, 1, MPI_INT, 3, 1, diag_comm, MPI_STATUS_IGNORE);
		init_num = my_num;
		my_num = new_num;
	}
}


printf("Rank: %d Num: %d\n", rank, my_num);
MPI_Comm_free(&diag_comm);

MPI_Finalize();
}

