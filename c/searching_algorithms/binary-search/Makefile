PROG=search
CC=gcc
CFLAGS=-std=c99
SRC=binary_search

.PHONY: all

all: ${PROG}

test: all
	./${PROG}

${PROG}: ${SRC}.o main.o
	${CC} ${CFLAGS} ${SRC}.o main.o -o ${PROG}

main.o: main.c
	${CC} ${CFLAGS} main.c -c

${SRC}.o: ${SRC}.c
	${CC} ${CFLAGS} ${SRC}.c -c
	
clean: 
	@if test -f ${PROG}; then rm -f ${PROG}; fi
	@if test -f ${SRC}.o; then rm -f ${SRC}.o; fi
	@if test -f main.o; then rm -f main.o; fi
