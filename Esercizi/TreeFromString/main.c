#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "item.h"

int main(int argc, char* argv[]) {
    Btree a = newTree();

    for(int i = 0; i < 7; i++) {
        char* tmp = malloc(sizeof(char));
        *tmp = argv[1][i];
        out_item(tmp);
        /*Riempi albero con la funzione che stai per scrivere*/
        fromString(&a, tmp);
    }

    printf("\nAlbero A: ");
    visitByLevels(a);
    printf("\n");

    printf("\nAlbero A: ");
    inOrder(a);
    printf("\n");
}