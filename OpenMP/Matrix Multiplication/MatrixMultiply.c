#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define n 1000

int main(){

	int i, j, k, sum;
	int a[n][n], b[n][n], c[n][n];

	srand(time(NULL));

	double start = omp_get_wtime();

#pragma omp parallel for private(i,j)
		for(i=0; i<n; i++){		
			for(j=0; j<n; j++){
				#pragma omp sections
				{
					#pragma omp section				
					a[i][j] = (rand() % 50);
					#pragma omp section				
					b[i][j] = (rand() % 50);
				}
			}
		}
#pragma omp parallel for reduction(+:sum) private(i,j,k)
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			for(k=0; k<n; k++){
				sum =  sum + a[i][k]*b[k][j];
			}
			c[i][j] = sum; 
			sum = 0;
		}
	}

	double diff = (omp_get_wtime() - start)*1000;
	printf("time in ms: %.3f\n", diff);

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			//			printf("c[%d][%d] = %d\n", i, j, c[i][j]);
		}
	}

	return 0;
}
