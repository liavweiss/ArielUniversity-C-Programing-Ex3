CC = gcc
FLAGS = -Wall -c

all: txtfind isort

txtfind: txtfind.o
	$(CC) -Wall -o txtfind txtfind.o
isort: isort.o
	$(CC) -Wall -o isort isort.o
txtfind.o: txtfind.c
	$(CC) $(FLAGS) -fPIC -c txtfind.c
isort.o: isort.c
	$(CC) $(FLAGS) -fPIC -c isort.c

.PHONY: clean all

clean:
	rm -f *.o *.a txtfind isort a.out
