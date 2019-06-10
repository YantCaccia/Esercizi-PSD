#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "item.h"

int main(int argc, char* argv[]) {
    Btree a = newTree();
    Btree b = newTree();

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    Item arb[7];

    for(int i = 0; i < 7; i++) {
        int* tmp = malloc(sizeof(int));
        *tmp = arr[i];
        arb[i] = tmp;
    }

    int arrr[7] = {1, 3, 4, 5, 6, 7, 8};
    Item arbb[7];

    for(int i = 0; i < 7; i++) {
        int* tmp = malloc(sizeof(int));
        *tmp = arr[i];
        arbb[i] = tmp;
    }

    balanced(&a, arb, 0, 7);
    balanced(&b, arbb, 0, 7);

    printf("\nAlbero A: ");
    visitByLevels(a);
    printf("\n");

    printf("\nAlbero B: ");
    visitByLevels(b);
    printf("\n");

    printf("areEquals: [%d]\n", areEquals(a, b));
}