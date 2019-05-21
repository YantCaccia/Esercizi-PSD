wlist :	utils.o main.o int-item.o list.o queue-list.o
	gcc utils.o main.o int-item.o list.o queue-list.o -o driver.out

list.o :
	gcc -c list.c
	
utils.o :
	gcc -c utils.c
	
main.o :
	gcc -c main.c

stack.o :
	gcc -c stack.c
	
int-item.o:
	gcc -c int-item.c

queue-list.o:
	gcc -c queue-list.c

string-item.o:
	gcc -c string-item.c

clean: 
	rm -f *.o *.exe *.out
