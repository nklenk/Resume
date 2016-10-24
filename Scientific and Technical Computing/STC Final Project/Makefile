Compare: Compare.o makematrix.o
	icc -o Compare Compare.o makematrix.o

Compare.o: Compare.c parameters.h
	icc -c Compare.c

makematrix.o: makematrix.c parameters.h
	icc -c makematrix.c

clean:
	rm *.o compare makematrix

