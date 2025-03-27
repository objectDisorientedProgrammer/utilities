PROG=selectionSortTester
CC=gcc
CFLAGS=-std=c99
SRC=test.c selectionSort.c

.PHONY: all

all: ${PROG}

test: all
	./${PROG}

${PROG}: test.c selectionSort.o
	${CC} ${CFLAGS} ${SRC} -o ${PROG}

build: selectionSort.c
	${CC} ${CFLAGS} -c $^
	
clean: 
	@if test -f ${PROG}; then rm -f ${PROG}; fi
	@if test -f *.o; then rm -f *.o; fi
