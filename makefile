all: file.o
	gcc file.o

file.o: file.c
	gcc -c file.c

run:
	./a.out

clean:
	rm *.o
	rm text.txt
