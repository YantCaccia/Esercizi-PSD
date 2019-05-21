tr: btree.o string-item.o main.o
	gcc btree.o string-item.o main.o -o test.exe

btree.o:
	gcc -c btree.c

string-item.o:
	gcc -c string-item.c

main.o:
	gcc -c main.c

clean:
	rm *.exe *.out *.o