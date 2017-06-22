Neil Klenk (nlk322)

	In this exercise the effects of work sharing constructs, and their associated clauses were used to enhance a matrix multiplication program at 3 sizes: 10x10, 100x100, 1000x1000.
	The times were then compared to those collected in a previous exercise.

	A parallel for with private i and j were used to assign the matrices random values. The actual assignment of the matrix location with the random number was cut into 2 sections: one for each the a and b matrix.

	A second parallel for was used with private i, j, and k variables along with a reduction clause at the end. This allowed the threads to progress though the iterations more quickly with the reduction acting to combine all of the sums calculated across the threads.

	This code had a significant time decreases when compared to the same matrix multiplication done previously. This time reduction was a result of changing where the parallel for construct was located, the introduction of the omp sections construct, and the introduction of a reduction clause.

	A parallel for construct was added to for loops associated with giving the a and b matrix their initial values to allow it to be parallelized. The sections construct broke up the actual assignment of the matrix locations to their random values into on section for each matrix, and allowing all of their work to be divided between all of the threads in the team. The recuction clause had all of the threads add up their result values to update the master thread's global copy.

	The result of all of these changes is as follows

	n=	Before		After
	10	32.94(ms	0.036(ms)
	100	37.84(ms)	7.047(ms)
	1000	43.96(ms)	7357(ms)

compile this program with the "make" command.
