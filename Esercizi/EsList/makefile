tr: int-item.o list.o utils.o main.o
	gcc int-item.o list.o utils.o main.o -o test.exe

str: utils.o list.o string-item.o main.o
	gcc utils.o list.o string-item.o main.o -o test.exe

int-item.o:
	gcc -c int-item.c

string-item.o:
	gcc -c string-item.c

list.o:
	gcc -c list.c

utils.o:
	gcc -c utils.c

main.o:
	gcc -c main.c

clean:
	rm *.exe *.out *.o