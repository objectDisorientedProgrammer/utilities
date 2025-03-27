
CC=gcc
CFLAGS=-std=c99
SRC=quicksort.c

.PHONY: all

all: ${SRC}
	${CC} ${CFLAGS} $^ -c

# TODO add test
#test: all
#	./${PROG}
	
clean: 
	@if test -f *.o; then rm -f *.o; fi
