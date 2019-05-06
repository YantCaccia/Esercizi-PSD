int :	utils.o main.o int-item.o list.o stack.o queue.o
	gcc utils.o main.o int-item.o list.o stack.o queue.o -o driver.exe
	
str :	utils.o main.o string-item.o list.o stack.o queue.o
	gcc utils.o main.o string-item.o list.o stack.o queue.o -o driver.exe

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

queue.o:
	gcc -c queue.c
	
string-item.o:
	gcc -c string-item.c

clean: 
	rm -f *.o *.exe