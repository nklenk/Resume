CC = mpicc
CFLAGS = -o

all: exe5 Pingpong Pingpong_str

exe5: Exe5.c
	$(CC) $(CFLAGS) $@ $^

Pingpong: Pingpong.c
	$(CC) $(CFLAGS) $@ $^

Pingpong_str: Pingpong_str.c
	$(CC) $(CFLAGS) $@ $^

.PHONY: clobber clean neat echo
clobber: clean
	$(RM) $(EXEC)
clean: neat
	$(RM) $(OBJ)
echo:
	@echo $(OBJ)


