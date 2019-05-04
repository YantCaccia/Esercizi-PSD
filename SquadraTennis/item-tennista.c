#include "tennista.h"
#include "item.h"
#include <stdio.h>

Item inputItem(){

    char nome[50], data[12];
    int categoria;

    printf("Nome tennista:\n");
    scanf(" %[^\n]", nome);

    getchar();

    printf("Data di nascita del tennista (gg-mm-aaaa):\n");
    scanf(" %[^\n]", data);

    getchar();

    ctg: {
    printf("Categoria tennista:\n");
    scanf("%d", &categoria);
    }

    if(categoria>4||categoria<1){
        fprintf(stderr, "Illegal category number!\nTry again.\n");
        goto ctg;
    }

    else return newTennista(nome, data, categoria);
}

void outputItem(Item item){
    
    Tennista tennista = item;

    printf("Nome tennista: %s\n", getName(tennista));
    printf("Data di nascita del tennista: %s\n", getBirthDate(tennista));
    printf("Categoria tennista: %d\n", getCat(tennista));

}

int cmpItem(Item a, Item b){
    
    Tennista t1 = a;
    Tennista t2 = b;

    return (getCat(t1)-getCat(t2));
}

Item cloneItem(Item item){
    
    Tennista originale = item;
    Tennista clone = newTennista(getName(originale), getBirthDate(originale), getCat(originale));

    return clone;
}