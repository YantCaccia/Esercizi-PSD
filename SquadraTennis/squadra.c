#include "squadra.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct squadra {
    char nome[50];
    char indirizzo[50];
    int numerocampi;
    List tennisti;
};

Squadra newSquadra(char* nome, char* indirizzo, int num){
    Squadra squadra = malloc(sizeof(struct squadra));
    strcpy(squadra->nome,nome);
    strcpy(squadra->indirizzo,indirizzo);
    squadra->numerocampi=num;
    squadra->tennisti = newList();

    return squadra;

}

Squadra inTennista(Squadra squadra, Tennista tennista){
    addHead(squadra->tennisti, tennista);
    return squadra;
}

Squadra outTennista(Squadra squadra, int pos){
    removePos(squadra->tennisti, pos);
    return squadra;
}

Squadra forwardTennista(Squadra squadra, int pos){
    Item i1 = removePos(squadra->tennisti, pos);
    Item i2 = removePos(squadra->tennisti, pos);

    addItem(squadra->tennisti, i2, pos);
    addItem(squadra->tennisti, i1, pos + 1);
}

List cloneTennistsByCategory(Squadra squadra, int cat){
    
    Tennista t = newTennista(" ", " ", cat);
    
    List clone = cloneList(squadra->tennisti);

    List byCategory = newList();

    Item p = removeHead(clone);

    for(;isEmpty(clone)!=1;p=removeHead(clone)){
        if(cmpItem(p,t)==0){
            addHead(byCategory, p);
        }
    }

    free(clone);

    return byCategory;

}

void printSquadra(Squadra squadra){
    printf("\nNome squadra: %s\nIndirizzo circolo: %s\nNumero campi disponibili: %d\n\n", squadra->nome, squadra->indirizzo, squadra->numerocampi);
    printList(squadra->tennisti);
}