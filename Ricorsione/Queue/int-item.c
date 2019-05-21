#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item in_item() {
    int *t = malloc(sizeof(int));
    scanf("%d", t);
    return t;
}

void out_item(Item a) {
    int *b = a;
    printf("%d ", *b);
}

int comp_items(Item a, Item b) {
    int *a1 = a;
    int *b1 = b;
    return (*a1 - *b1);
}