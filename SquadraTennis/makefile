int :	list.o main.o item-int.o
	gcc list.o main.o item-int.o -o list.exe
	
str :	list.o main.o item-string.o
	gcc list.o main.o item-string.o -o list.exe

tn :	list.o main.o item-tennista.o squadra.o tennista.o
	gcc list.o main.o item-tennista.o squadra.o tennista.o -o tn.exe
		
list.o :
	gcc -c list.c

squadra.o :
	gcc -c squadra.c

tennista.o :
	gcc -c tennista.c
	
main.o :
	gcc -c main.c

item-int.o :
	gcc -c item-int.c
	
item-string.o :
	gcc -c item-string.c 

item-tennista.o :
	gcc -c item-tennista.c
	
clean: 
	rm -f *.o *.exe