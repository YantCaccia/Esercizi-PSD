#include "garage.h"
#include "auto.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct garage {
    char nome[20];
    char indirizzo[20];
    int numeroPosti;
    List cars;
};

Garage newGarage(char* nome, char* indirizzo, int posti){
    
	Garage garage = malloc(sizeof(struct garage));
    strcpy(garage->nome, nome);
    strcpy(garage->indirizzo, indirizzo);
    garage->numeroPosti = posti;
    garage->cars = newList();

    return garage;
}

Garage insertCar(Garage garage, Car car){
    
	addHead(garage->cars, car);

    return garage;
}

Garage removeCar(Garage garage, int pos){
    
	removePos(garage->cars, pos);

    return garage;
}

Garage forwardCar(Garage garage, int pos){

	int size = sizeList(garage->cars);
	printf("SIZE: %d\n", size);

	if(pos==size-1){
		printf("Unable to forward: indicated position is the last one.\n");
	}
	else{
		Item car1 = removePos(garage->cars, pos);
		Item car2 = removePos(garage->cars, pos);

		addItem(garage->cars, car2, pos);
		if(pos==(size-2))
			addTail(garage->cars, car1);
		else
			addItem(garage->cars, car1, pos + 1);

		return garage;
	}
}

List listBySegment(Garage garage, int seg){
	
	List clone = cloneList(garage->cars);
	List subList = newList();

	Car temp = newCar("", 1, seg);

	Item p = removeHead(clone);

	for(;!isEmpty(clone);p=removeHead(clone)){
		// printf("Sono entrato nel ciclo for di listBySegment\n");
		if(cmpItem(p, temp)==0){
			addHead(subList, p);
			// printf("Sono entrato nell'if di listBySegment\n");
		}
	}

	free(clone);
	return subList;	
}

void printGarage(Garage garage){
    printf("Nome garage: %s\nIndirizzo garage: %s\nNumero posti disponibili: %d\n", garage->nome, garage->indirizzo, garage->numeroPosti);
    printList(garage->cars);
}