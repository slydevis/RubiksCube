SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall

OBJ = test.o

EXECS = main.out

all :: clean
all :: $(EXECS) 

main.out: src/main.c $(OBJ)
	$(CC) $(CFLAGS) -o output/$(EXECS) src/main.c output/$(OBJ)
test.o:
	$(CC) $(CFLAGS) -c src/test/test.c && cp test.o output/test.o && rm test.o

debug: clean
debug: CFLAGS += -DDEBUG
debug: $(EXECS) 

clean ::
	\rm -f output/*.o output/*.out
