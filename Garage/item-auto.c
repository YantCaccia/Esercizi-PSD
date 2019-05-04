#include <stdio.h>
#include <string.h>
#include "auto.h"
#include "item.h"

Item inputItem(){
    char nome[20];
    int anno, seg;

    printf("Nome auto: ");
    scanf(" %[^\n]", nome);
    getchar();

    printf("Anno di immatricolazione: ");
    scanf(" %d", &anno);
    
    insertSeg: {
    printf("Segmento (1-6): ");
    scanf(" %d", &seg);
    }

    if(seg<1||seg>6){
        printf("Illegal segment code. Try again\n");
        goto insertSeg;
    }
    else
        return newCar(nome, anno, seg); 

}

void outputItem(Item item){
    Car car = item;
    
    printf("\nNome auto: %s\n", getNome(car));
    printf("Anno di immatricolazione: %d\n", getYear(car));
    printf("Segmento: %d\n", getSegment(car));

}

int cmpItem(Item a, Item b){
    Car c1 = a;
    Car c2 = b;

    int seg1 = getSegment(c1);
    int seg2 = getSegment(c2);

    // printf("Seg1: [%d]\nSeg2: [%d]\n", seg1, seg2);

    return seg1 - seg2;
}

Item cloneItem(Item item){
    Car c1 = item;
    char nome[20];
    strcpy(nome, getNome(c1));
    int anno = getYear(c1);
    int segm = getSegment(c1);

    Car c2 = newCar(nome, anno, segm);

    return c2;
}