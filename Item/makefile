int :	utils.o array.o main.o int-item.o
	gcc utils.o array.o main.o int-item.o -o driver.exe
	
str :	utils.o array.o main.o string-item.o
	gcc utils.o array.o main.o string-item.o -o driver.exe

point :	utils.o array.o main.o point-item.o point.o
	gcc utils.o array.o main.o point-item.o point.o -o driver.exe
	
utils.o :
	gcc -c utils.c

array.o :
	gcc -c array.c
	
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
	rm -f utils.o array.o main.o int-item.o string-item.o point-item.o point.o driver.exe