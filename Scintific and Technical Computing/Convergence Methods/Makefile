# Files
EXEC := integrate
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC))

# Options
CC := gcc
CFLAGS := -O3
LDFLAGS := -L/nklenk/lib
LDLIBS := -lm
# Rules
$(EXEC) : $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o: %.c
	$(CC)  $(CFLAGS) -c $<
routines.o prog.o: parameters.h

#useful phony targets
.PHONY: clean
clean: 
	rm  *.o

run:
	./integrate

