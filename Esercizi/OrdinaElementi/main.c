/*Produce un ordinamento partendo da un vettore utilizzando un BST*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "list.h"

int main(int argc, char* argv[]) {
    Btree h = newTree();

    for(int i = 1; i < argc; i++) {
        int* tmp = malloc(sizeof(int));
        *tmp = atoi(argv[i]);
        insert(&h, tmp);
    }

    printf("Albero: ");
    inOrder(h);
    printf("\n");
}