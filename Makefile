SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall

OBJ =

#EXECS = main

all :: clean
#all :: $(EXECS) 
all :: main.out

main.out :
	$(CC) $(CFLAGS) -o output/main.out src/main.c $(OBJ)
	
debug : clean
debug : CFLAGS += -DDEBUG
debug : $(EXECS) 

clean ::
	\rm -f output/*.o output/*.out
