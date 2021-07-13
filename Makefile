#Makefile

all: add-nbo

add-nbo: FileRead.o main.o
	g++ -o add-nbo FileRead.o main.o

#main.o: FileRead.h main.c

FileRead.o: FileRead.h FileRead.c
	g++ -c -o FileRead.o FileRead.c

main.o: main.c FileRead.h
	g++ -c -o main.o main.c

clean:
	rm -f add-nbo
	rm -f *.o


