
# compiler
CC=gcc
# compile flags
CFLAGS=-std=c99
# files
SRC= insertion-sort.c
OBJ= insertion-sort.o
HEADER = insertion-sort.h
# executable
EXE=insertion_sort

# TODO
#all: ${EXE}
all: ${OBJ}

# TODO 
#${EXE}: ${OBJ}
#	${CC} ${OBJ} -o ${EXE}

${OBJ}: ${SRC} ${HEADER}
	${CC} ${CFLAGS} ${SRC} -c

# TODO add tests
#test: all
#	./${PROG}
	
clean: 
	@if test -f ${OBJ}; then rm -f ${OBJ}; fi
	@if test -f ${EXE}; then rm -f ${EXE}; fi

.PHONY: all clean

