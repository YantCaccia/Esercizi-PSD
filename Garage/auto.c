#include "auto.h"
#include <string.h>
#include <stdlib.h>

struct car {
    char nome[20];
    int anno;
    int segmento;
};

char* getNome(Car car){
    return car->nome;
}

int getYear(Car car){
    return car->anno;
}

int getSegment(Car car){
    return car->segmento;
}

Car newCar(char* nome, int anno, int seg){
    
    Car car = malloc(sizeof(struct car));

    strcpy(car->nome, nome);
    car->anno = anno;
    car->segmento = seg;

    return car;
}