tr: btree.o int-item.o main.o
	gcc btree.o int-item.o main.o -o test.exe

str: btree.o string-item.o main.o
	gcc btree.o string-item.o main.o -o test.exe

btree.o:
	gcc -c btree.c

int-item.o:
	gcc -c int-item.c

string-item.o:
	gcc -c string-item.c

main.o:
	gcc -c main.c

clean:
	rm *.exe *.out *.o