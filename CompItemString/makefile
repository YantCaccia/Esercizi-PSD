str :	utils.o vettore.o main.o item-string.o
	gcc utils.o vettore.o main.o item-string.o -o vettore.exe

driver :	utils.o vettore.o driver.o item-string.o
	gcc utils.o vettore.o driver.o item-string.o -o driver.exe
	
utils.o :
	gcc -c utils.c
	
vettore.o :
	gcc -c vettore.c
	
driver.o :
	gcc -c driver.c
	
main.o :
	gcc -c main.c
	
item-int.o :
	gcc -c item-int.c
	
item-string.o :
	gcc -c item-string.c 
	
clean: 
	rm -f *.o *.exe