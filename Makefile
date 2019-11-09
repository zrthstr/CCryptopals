
runall:
	./c11

test: all runall

all: c11

c11:
	gcc -o c11 c11.c


