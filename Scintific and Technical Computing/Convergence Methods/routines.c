<<<<<<< HEAD
/*
 * routines.c
 *
 *  Created on: Sep 20, 2015
 *      Author: Neil Klenk
 */
#include "parameters.h"
#include <math.h>

double midp(double xi, double h){
	return pow( (xi + h*0.5e0), (double)7 ); // returns sum for use in prog.c --> do i need this?
}

double trap(double xi, double h){
	return pow( xi, (double)7 ) + pow( (xi+h), (double)7);
}

double simp(double xi, double h){
	return pow( (xi-h), (double)7 )+ 4*pow( xi, (double)7 )+pow( (xi+h), (double)7 );
}



=======
void isqrt(float *a,int n){
  int i;
//               Vector inverse square
//               Someone advised to
//               making two separate loops.

                 for(i=0;i<n;i++) a[i] = 1/sqrt(a[i]); 
 }
>>>>>>> f3d22e97233b95c06f69f0cfcd591c27ac2a403b
