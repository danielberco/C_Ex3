all: txtfind isort

txtfind: text.o
	gcc -Wall -o txtfind text.o

isort: isort.o
	gcc -Wall -o isort isort.o

isort.o: isort.c
	gcc -Wall -c isort.c -o isort.o

text.o: text.c
	gcc -Wall -c text.c -o text.o

.PHONY: clean all

clean :
	rm -f *.o *.out
