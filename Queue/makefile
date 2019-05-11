wlist :	utils.o main.o int-item.o list.o queue-list.o
	gcc utils.o main.o int-item.o list.o queue-list.o -o driver.out

warr :	utils.o main.o int-item.o list.o queue-arr.o
	gcc utils.o main.o int-item.o list.o queue-arr.o -o driver.exe

warrdin :	utils.o main.o int-item.o queue-arr-din.o
	gcc utils.o main.o int-item.o queue-arr-din.o -o driver.exe
	
str :	utils.o main.o string-item.o list.o stack.o queue-list.o
	gcc utils.o main.o string-item.o list.o stack.o queue-list.o -o driver.exe

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
	
queue-arr.o:
	gcc -c queue-arr.c

queue-arr-din.o:
	gcc -c queue-arr-din.c

string-item.o:
	gcc -c string-item.c

clean: 
	rm -f *.o *.exe *.out
