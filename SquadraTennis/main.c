#include<stdio.h>
#include "item.h"
#include "squadra.h"

int main(void){

    Squadra squadra = newSquadra("SSC Napoli", "Via Napoli 25", 6);

    Tennista t1 = inputItem();
    Tennista t2 = inputItem();
    Tennista t3 = inputItem();
    Tennista t4 = inputItem();
    Tennista t5 = inputItem();

    inTennista(squadra, t1);
    inTennista(squadra, t2);
    inTennista(squadra, t3);
    inTennista(squadra, t4);
    inTennista(squadra, t5);

    printSquadra(squadra);

    printf("\n\n");

    printList(cloneTennistsByCategory(squadra, 2));

    printf("\n\n");
    
    return 1;
}