int :	utils.o main.o list.o int-item.o
	gcc utils.o main.o int-item.o list.o -o driver.exe
	
str :	utils.o main.o string-item.o list.o
	gcc utils.o main.o string-item.o list.o -o driver.exe

point :	utils.o main.o point-item.o point.o list.o
	gcc utils.o main.o point-item.o point.o list.o -o driver.exe

list.o :
	gcc -c list.c
	
utils.o :
	gcc -c utils.c
	
driver.o :
	gcc -c driver.c
	
main.o :
	gcc -c main.c
	
int-item.o:
	gcc -c int-item.c
	
string-item.o:
	gcc -c string-item.c

point-item.o:
	gcc -c point-item.c

point.o:
	gcc -c point.c

clean: 
	rm -f utils.o main.o int-item.o string-item.o point-item.o point.o list.o driver.exe