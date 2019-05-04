#include "tennista.h"
#include <stdlib.h>
#include <string.h>

struct tennista {
    char nome[50];
    char birthDate[12];
    int cat;
};

char* getName(Tennista tennista){
    return tennista->nome;
}

char* getBirthDate(Tennista tennista){
    return tennista->birthDate;
}

int getCat(Tennista tennista){
    return tennista->cat;
}

Tennista newTennista(char* nome, char* data, int categoria){
    Tennista tennista = malloc(sizeof(struct tennista));
    strcpy(tennista->nome, nome);
    strcpy(tennista->birthDate, data);
    tennista->cat = categoria;

    return tennista;
}