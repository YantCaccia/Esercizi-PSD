int :	utils.o main.o list.o esame-item.o libretto.o esame.o
	gcc utils.o main.o esame-item.o list.o libretto.o esame.o -o driver.exe

list.o :
	gcc -c list.c
	
utils.o :
	gcc -c utils.c
	
main.o :
	gcc -c main.c
	
int-item.o:
	gcc -c int-item.c
	
string-item.o:
	gcc -c string-item.c

libretto.o:
	gcc -c libretto.c

esame-item.o:
	gcc -c esame-item.c

esame.o:
	gcc -c esame.c

clean: 
	rm -f utils.o main.o int-item.o string-item.o list.o libretto.o esame-item.o esame.o driver.exe