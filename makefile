all: sig.o
	gcc sig.o

run:
	./a.out

clean:
	-rm -rf ./a.out *.o

sig.o:
	gcc -c sig.c
