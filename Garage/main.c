#include "garage.h"
#include "auto.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main (void){

    Garage garage = newGarage("Garage di Antonio", "Via Napoli 25", 20);

    Item c1 = inputItem();
    Item c2 = inputItem();
    Item c3 = inputItem();
    Item c4 = inputItem();

    insertCar(garage, c1);
    insertCar(garage, c2);
    insertCar(garage, c3);
    insertCar(garage, c4);

    printf("\nGarage normale:\n");
    printGarage(garage);
    printf("\n\n");

    removeCar(garage, 3);

    printf("Garage dopo remove:\n");
    printGarage(garage);
    printf("\n\n");

    forwardCar(garage, 2);

    printf("Garage dopo forward:\n");
    printGarage(garage);
    printf("\n\n");

    printf("Lista segmenti:\n");
    printList(listBySegment(garage, 3));
    printf("\n\n");

    return 1;
}