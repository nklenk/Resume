<<<<<<< HEAD
/*
 * prog.c
 *
 *  Created on: Sep 20, 2015
 *      Author: Neil Klenk
 */

#include "parameters.h"
#include <stdio.h>
#include <time.h>

int M = 7;
double actual = 0.125;
double xi, h;
double err_m, err_t, err_s;
double x_start = 0;
double x_end = 1;
int N[] = {11, 101, 1001, 10001, 100001, 1000001, 10000001};

int main(){
	int i;
	for (i=0; i<sizeof(N)/sizeof(N[0]); i++){
		double sum_midp = 0 , sum_trap = 0, sum_simp = 0;
		M = N[i];
		h = (x_end - x_start)/(N[i]-1);
		xi = x_start;
		int j;
		clock_t begin, end;
		double time_spent_midp, time_spent_trap, time_spent_simp;
		begin = clock();
		for (j=0; j<M; j++){
			xi = xi + h;
			sum_midp +=  midp(xi, h); //sum = total sum for integration steps
		}
		end = clock();
		time_spent_midp = (double)(end-begin) / CLOCKS_PER_SEC;
		xi = x_start;
		begin = clock();
		for (j=0; j<M; j++){
			xi = xi + h;
			sum_trap += trap(xi, h);
		}
		end = clock();
		time_spent_trap = (double)(end-begin) / CLOCKS_PER_SEC;
		xi = x_start;
		begin = clock();
		for (j=1; j<M; j+=2){
			xi = xi + h;
			sum_simp += simp(xi, h);
		}
		end = clock();
		time_spent_simp = (double)(end-begin) / CLOCKS_PER_SEC;
		sum_midp = h *sum_midp;
		sum_trap = (h/2) *sum_trap;
		sum_simp = (h/3) *sum_simp;
		err_m = actual - sum_midp;
		err_t = actual - sum_trap;
		err_s = actual - sum_simp;
		printf(" \n");
		printf("N:%i \n", N[i]);
		printf("Midpt: %.13f, Midpt_err: %.13f, Midpt_Speed: %.13f \n", sum_midp, err_m, time_spent_midp);
		printf("Trapz: %.13f, Trapz_err: %.13f, Trapz_Speed: %.13f \n", sum_trap, err_t, time_spent_trap);
		printf("Simps: %.13f, Simps_err: %.13f, Simps_Speed: %.13f \n", sum_simp, err_s, time_spent_simp);
	}
}

=======
#define N 100
void isqrt(float *a,int n);

main(){
float a[N];
int i;
int N = 1000000;
   for(i=0; i<N; i++) a[i]=1.0e0 + i;
   isqrt(a,N);
   printf("N a(0) a(N-1): %d %f %f\n", N,a[0],a[N-1]);
}

>>>>>>> f3d22e97233b95c06f69f0cfcd591c27ac2a403b
