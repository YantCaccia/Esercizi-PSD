str :	list.o main.o item-auto.o garage.o auto.o
	gcc list.o main.o item-auto.o garage.o auto.o -o garage.exe
		
list.o :
	gcc -c list.c

garage.o :
	gcc -c garage.c

auto.o :
	gcc -c auto.c
	
main.o :
	gcc -c main.c

item-int.o :
	gcc -c item-int.c
	
item-string.o :
	gcc -c item-string.c

item-auto.o :
	gcc -c item-auto.c
	
clean: 
	rm -f *.o *.exe