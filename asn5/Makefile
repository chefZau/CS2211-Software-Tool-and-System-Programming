all: mymatrix
	gcc datatype.c matrix.c bstree.c main.c -o mymatrix

mymatrix: main.o datatype.o bstree.o matrix.o
	gcc main.o datatype.o bstree.o matrix.o -o mymatrix

main.o: main.c
	gcc -c main.c

datatype.o: datatype.c
	gcc -c datatype.c

bstree.o: bstree.c
	gcc -c bstree.c

matrix.o: matrix.c
	gcc -c matrix.c

clean:
	rm -rf *o mymatrix