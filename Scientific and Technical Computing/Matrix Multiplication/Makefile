CC = icc
CFLAGS = -O3


BLAS = -L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread -lm

INC = -I${MKLROOT}/include/

all:  linear_equation_c linear_inverse_c 

linear_equation_c: linear_equation.c
	$(CC) $(FFLAGS) $(INC) $(BLAS) linear_equation.c -o linear_equation_c 

linear_inverse_c: linear_inverse.c
	$(CC) $(FFLAGS) $(INC) $(BLAS) linear_inverse.c -o linear_inverse_c 

clean: 
	rm -rf *.o linear_equation_c linear_inverse_c         
