In this program, I explored the speedup seeing using different types of scheduling (static, dynamic, and guided). The results are below.
Please compile with the "make" command.

When using the static scheduling, the best speedup that we saw occured when n=7 while there were 10 threads avaliable. 
     The reason that the maximum speedup was not seen when n matched the number of avaliabe threads was because some of the avaliable threads are always beeing uses for background processes

Just using schedule(dynamic) gave a bad example because iterations are assigned to threads that are unoccupied, and thus are ideally used only when iterations take an unpredictable amount of time.

Using schedule(guided) gave the one of the longest times.
    it took about 20s as copared to an average static time of 2s.
