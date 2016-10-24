Neil Klenk (nlk322)

	Homework 9

	In this exercise, the value of locks on parallel programs was explored. Locks function by restricting access to a specific data location, giving a particular task exclusive access until the lock is released. 

	The locks were set around the parallel region that solved for i and j, the two proceeding numbers in the fibonacci sequence. This prevented any other portion of the code from accessing those portions of data while an array was built of all the preceding numbers in the fibonacci sequence. Without the locks, data races occured which dammaged the speed and reliability of the program.  

