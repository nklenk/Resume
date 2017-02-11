Please use one node and 16 tasks for each exercise. 

In exercise 1 I learned about how subcommunicators work, and the ways in which their implementation can be beneficial to a program.
I two different communicators, one for the rows and one for the columns. 
I then assigned the first processor in each column/row to the value of that column/row, and broadcast that value to all the other in the colum/row via the communicators

In exercise 2 I learned about the power of symmetry when using communicators. 
I split up a 4x4 matrix into 3 subsections that could communicate within each other.
MPI_Send and MPI_Recv were then used within each subcommunicator to swap the values necessary to transpose the matrix.


