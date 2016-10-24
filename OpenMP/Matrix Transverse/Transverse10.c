#include <stdio.h>	
#include <stdlib.h>
#include "omp.h"

#define n 10 

//function declaration
int **get_array();
int **distance(int **count_mat);
int min(int l, int p);
int *trace_back(int **trace_mat);

int main(){

	int i, j;
	double start = omp_get_wtime();

	omp_set_dynamic(0);
	omp_set_num_threads(10);

	//allocating room for the array of pointers	
	int **mat=malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		mat[i] = malloc(n*sizeof(int));
	}
	int **dist_mat=malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		dist_mat[i] = malloc(n*sizeof(int*));
	}
	int *trace=malloc((4*n)*sizeof(int));

	mat = get_array();

	dist_mat = distance(mat);

	trace = trace_back(dist_mat);

	double end = omp_get_wtime();
	printf("Prog took: %lf sec \n", end-start);
}

int min(int l, int p){

	if(l<p){
		return l;
	}
	else{
		return p;
	}
}


//function to read in the array
int ** get_array(){

	FILE *file;

	int i,j;
	int **my_mat=malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		my_mat[i] = malloc(n*sizeof(int));
	}

	file = fopen("MatrixTransverse10.dat", "r");

	while(!feof(file)){
#pragma omp parallel for shared(i,j) schedule(static)
			for(i=0; i<n; i++){ 
				for(j=0; j<n; j++){
					fscanf(file, "%1d", &my_mat[i][j]);
				}
			}
		
	}	
	fclose(file);
	return my_mat;
}

int **distance(int **count_mat){

	int i, j=0;
	int **my_dist = malloc((n)*sizeof(int*));
	for(i=0; i<n; i++){
		my_dist[i] = malloc(n*sizeof(int));
	}

	//zero out my_count matrix
#pragma omp paralel for private(i,j) schedule(static)	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			my_dist[i][j] = 99;
		}
	}

	//Checking distance to start for each location in the matrix
//#pragma omp parallel for private(i,j) collapse(2)
	for(i=0; i<n-1; i++){
		for(j=0; j<n; j++){
			my_dist[0][0] = 0;
			if(count_mat[i][j] == 0){
				my_dist[i][j] = 99;
			}
			else if(count_mat[i+1][j] == 1 || count_mat[i][j+1] == 1){
				if(count_mat[i+1][j] == 1){
					my_dist[i+1][j] = min(my_dist[i][j]+1,my_dist[i+1][j]);//need a min function to know which to keep
				}
				if(count_mat[i][j+1] == 1){
					my_dist[i][j+1] = min(my_dist[i][j]+1,my_dist[i][j+1]);	
				}
			}
			else{
				my_dist[i][j] = my_dist[i][j];	
			}		
		}
	}
return my_dist;
}

int *trace_back(int **trace_mat){

	int i=n-1, j=n-1, k=2;
	int *back_trace = malloc((4*n)*sizeof(int));

	back_trace[0] = 9;
	back_trace[1] = 9;

while(i!=0 || j!=0){
		if(i==0 && j==0){
			break;
		}
		else if(j==0){
			back_trace[k] = i-1;
			back_trace[k+1] = j;
			k+=2;
			i=i-1;		
		}
		else if(i==0){
			back_trace[k] = i;
			back_trace[k+1] = j-1;
			k+=2;
			j=j-1;
		}
		else if(trace_mat[i-1][j]<=trace_mat[i][j-1]){
			back_trace[k] = i-1;
			back_trace[k+1] = j;
			k+=2;
			i = i-1;
		}
		else if(trace_mat[i][j-1]<trace_mat[i-1][j]){
			back_trace[k] = i;
			back_trace[k+1] = j-1;
			k+=2;
			j=j-1;
		}
		else{
			printf("I'm Broken");
		}
	}
	for(k=0; k<38; k+=2){
		printf("(%d, %d) ", back_trace[k], back_trace[k+1]);
	}
	printf("\n");
}

