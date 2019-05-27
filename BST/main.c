#include <stdio.h>
#include "btree.h"
#include "item.h"

int main(void) {
    Btree h = newTree();
    int labels[] = {8, 6, 5, 9, 3, 7, 2};
    int n = sizeof(labels) / sizeof(int);

    for(int i = 0; i < n; i++) {
        Item item = &(labels[i]);
        insert(&h, item);
    }

    printf("Albero: ");
    preOrder(h);
    printf("\n");
}