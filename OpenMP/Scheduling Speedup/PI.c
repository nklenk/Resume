#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHUNKSIZE 100

int main(int argc, char **argv){

  int nsteps = 1000000000;
  double tstart, tend, elapsed, pi, quarterpi, h;
  int i;
  int x, y, chunk;

  tstart = omp_get_wtime();
	
  quarterpi = 0.;
  h = 1./nsteps;
#pragma omp parallel shared(x,h,y,chunk) private(i) 
  {
#pragma omp for reduction(+:quarterpi) schedule(guided) nowait
    for(i=0; i<nsteps; i++){
    double x = i*h, y = sqrt(1-x*x);
    quarterpi += h*y;
    }
  }
    pi = 4*quarterpi;
    tend = omp_get_wtime();
    elapsed = tend - tstart;

  printf("Computed pi = %e in %6.3f seconds\n", pi, elapsed);
  
  return 0;
}

