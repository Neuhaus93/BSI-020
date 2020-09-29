all: main

main: pilha.o main.o
	gcc -o main pilha.o main.o

main.o: main.c pilha.h
	gcc -c main.c

pilha.o: pilha.c pilha.h
	gcc -c pilha.c

run: main
	./main

clean:
	rm *.o main