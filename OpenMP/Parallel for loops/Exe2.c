#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 10

int main(int argc, char* argv[]){


int row, col, k, sum;
int mat_1[N][N], mat_2[N][N], mat_3[N][N];
double begin, end, time_taken;
time_t t;
int nthreads, tid;

srand((unsigned)time(&t));

//iniitializing the first two arrays
for(row=0; row<N; row++){
  for(col=0; col<N; col++){
    mat_1[row][col] = rand() % 50;
    mat_2[row][col] = rand() % 50;
  }
}


begin = omp_get_wtime();

//beginning simple parallel directive
#pragma omp parallel private(nthreads, tid)
{

//splitting of the for loop between the threads
#pragma omp for private(row, col, k)
  for(row=0; row<N; row++){
    for(col=0; col<N; col++){
      for(k=0; k<N; k++){
        sum = sum + mat_1[row][k] * mat_2[k][col];
      } 
      mat_3[row][col] = sum;
      sum = 0;
    }
  }
}
end = omp_get_wtime();

//evaluating total time taken in milliseconds
time_taken = (end-begin)*1000.0;
printf("ms taken: %f\n", time_taken);

}
