Neil Klenk

Homework 10

To run please compile with the "make" command.
The number of threads is set to 10 within the program.

In this exercise, a 10x10 matrix was traversed, and the shortest possible pathway found. A 100x100 case was also attempted, but the conversion to the larger case proved nontrivial.

There were some problems with the parallelization of my code. The biggest segment that proved problematic was a large while loop within the trace_back function. I attempted to convert it to a for loop with the indices going in reverse, so that a #pragma omp parallel for could be used. This worked sequentially, but as soon as the parallelized version was attempted, there was an error about invalid increment expression. My theory is that since I was decreasing the increments instead of increasing them like is more common, OpenMP didn't know how to handle it.

One region that proved more sensitive to parallelization was the for loop used to scan in the values from the .dat file. The #pragma omp parallel for with private variables in it  parallelization was the for loop used to
scan in the values from the .dat file. The #pragma omp parallel for with private variables in it taking about 1.5 times as long as the non parallel version, while if they were made into shared variables, a significant speedup was seen (~2 times as fast). 

Since we were dealing with matrices, nested for loops were common, and so the collapse(2) argument was used. This allowed the compiler to know to treat both loops as parallel ones. A small speedup was seen with this addition, but nothing huge (~.00005 sec).
