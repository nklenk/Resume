#include <stdlib.h>
#include <omp.h>
#include <stdio.h>

#define N 25 

int done[N] = {0};
int FibSeq[N] = {0};

omp_lock_t my_lock;

int fib(int n){

	omp_init_lock(&my_lock); //initializing the lock
	int i, j;
	if(!done[n]){
		if  (n<2){
			return n;
		}
		else{
#pragma omp task shared(i) firstprivate(n)
			omp_set_lock(&my_lock); //setting the lock 
			i=fib(n-1);
#pragma omp task shared (j) firstprivate(n) 
			j=fib(n-2);
			//omp_unset_lock(&my_lock); // unsetting the lock
#pragma omp taskwait
			FibSeq[n] = i+j;
			done[n] = 1; //only evaluates to 1 after finding FibSeq[n]
			omp_unset_lock(&my_lock);
		}
	}
	return FibSeq[n];
	omp_destroy_lock(&my_lock); // destroying the lock
}

int main(){

	int n = N;
	double start, end;	

	omp_set_dynamic(0);
	omp_set_num_threads(4);
	start = omp_get_wtime();

#pragma omp parallel shared(n) num_threads(4) //calculations are done in parallel
	{
#pragma omp single		// single thread prints
		printf("Fibonacci: %d\n", fib(n));
	}
	end = omp_get_wtime();
	printf("Time: %.4lf ms\n", (end-start)*1000);
}
