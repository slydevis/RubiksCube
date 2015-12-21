SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -std=c99
LIBFLAGS = -lSDL -lSDL_mixer
OBJ = test.o display.o file.o util.o

EXECS = main.out

all :: clean
all :: $(EXECS) 

debug:: clean
debug:: CFLAGS += -DDEBUG
debug:: $(EXECS) 

release:: clean
release:: CFLAGS += -O3
release:: $(EXECS)

clean ::
    \rm -f output/*.o output/*.out *.o

main.out: src/main.c $(OBJ)
    $(CC) $(CFLAGS) -o output/$(EXECS) src/main.c $(OBJ) $(LIBFLAGS) && rm $(OBJ)
test.o:
    $(CC) $(CFLAGS) -c src/test/test.c && cp test.o output/test.o
display.o:
    $(CC) $(CFLAGS) -c src/display.c && cp display.o output/display.o
file.o:
    $(CC) $(CFLAGS) -c src/file.c && cp file.o output/file.o
util.o:
    $(CC) $(CFLAGS) -c src/util.c && cp util.o output/util.o