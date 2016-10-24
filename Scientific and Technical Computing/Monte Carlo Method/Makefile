CC = icc
CFLAGS = -O3

BLAS = -L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread -lm

INC = -I${MKLROOT}/include/

all:  rand_uniform rand_exp rand_normal pi integral_unbiased integral_impotance

rand_uniform: rand_uniform.c
	$(CC) -o rand_uniform rand_uniform.c

rand_exp: rand_exp.c
	$(CC) -o rand_exp rand_exp.c -lm

rand_normal: rand_normal.c
	$(CC) -o rand_normal rand_normal.c -lm

pi: pi.c
	$(CC) -o pi pi.c -lm

integral_unbiased: integral_unbiased.c
	$(CC) -o integral_unbiased integral_unbiased.c

integral_biased: integral_importance.c
	$(CC) -o integral_importance integral_importance.c

clean: 
	rm -rf *.o rand_uniform rand_exp rand_normal pi integral_unbiased integral_importance                              

