int: int-item.o utils.o vettore.o main.o
	gcc int-item.o utils.o vettore.o main.o -o test.exe

str: string-item.o utils.o main.o
	gcc string-item.o utils.o main.o -o test.exe

vettore.o:
	gcc -c vettore.c

int-item.o:
	gcc -c int-item.c

string-item.o:
	gcc -c string-item.c

utils.o:
	gcc -c utils.c

main.o:
	gcc -c main.c

rm:
	rm *.o *.exe