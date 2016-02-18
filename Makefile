SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -std=c99
LIBFLAGS = -lSDL
OBJ = test.o display.o file.o util.o rotations.o resolution_mecanique.o resolveBacktrack.o cube.o \
      list.o tree.o

EXECS = main.out

rotations.h : src/rotations.h
rotations.c : src/rotations.c
 
resolution_mecanique.h : src/resolution_mecanique.h
resolution_mecanique.c : src/resolution_mecanique.c

util.c : src/util.c
util.h : src/util.h

file.h : src/file.h
file.c : src/file.c

display.h : src/display.h
display.c : src/display.c

test.h : src/test/test.h
test.c : src/test/test.c

resolveBacktrack.c : src/resolveBacktrack.c
resolveBacktrack.h : src/resolveBacktrack.h

cube.c : src/cube.c
cube.h : src/cube.h

list.c : src/list.c
list.h : src/list.h

tree.c : src/tree.c
tree.h : src/tree.h

all : $(EXECS)

debug : clean
debug : CFLAGS += -DDEBUG -g
debug : $(EXECS)

release : clean
release : CFLAGS += -O3
release : $(EXECS)

clean :
	\rm -f output/*.o output/*.out *.o

main.out : src/main.c $(OBJ)
	$(CC) $(CFLAGS) -o output/$(EXECS) src/main.c $(OBJ) $(LIBFLAGS)
	-rm $(OBJ)
test.o : test.h test.c
	$(CC) $(CFLAGS) -c src/test/test.c
	-cp test.o output/test.o
display.o : display.h display.c
	$(CC) $(CFLAGS) -c src/display.c
	-cp display.o output/display.o
file.o : file.h file.c
	$(CC) $(CFLAGS) -c src/file.c
	-cp file.o output/file.o
util.o : util.h util.c
	$(CC) $(CFLAGS) -c src/util.c
	-cp util.o output/util.o
rotations.o : rotations.c rotations.h
	$(CC) $(CFLAGS) -c src/rotations.c
	-cp rotations.o output/rotations.o
resolution_mecanique.o : resolution_mecanique.c resolution_mecanique.h
	$(CC) $(CFLAGS) -c src/resolution_mecanique.c
	-cp resolution_mecanique.o output/resolution_mecanique.o
resolveBacktrack.o : resolveBacktrack.h resolveBacktrack.c
	$(CC) $(CFLAGS) -c src/resolveBacktrack.c
	-cp resolveBacktrack.o output/resolveBacktrack.o
cube.o : cube.h cube.c
	$(CC) $(CFLAGS) -c src/cube.c
	-cp cube.o output/cube.o
list.o : list.h list.c
	$(CC) $(CFLAGS) -c src/list.c
	-cp list.o output/list.o
tree.o : tree.h tree.c
	$(CC) $(CFLAGS) -c src/tree.c
	-cp tree.o output/tree.o