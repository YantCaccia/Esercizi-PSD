#include "item.h"
#include <stdio.h>
#include <stdlib.h>

Item in_item() {
    Item a = malloc(sizeof(int));
    scanf("%d", a);
    return a;
}

void out_item(Item a) {
    int *b = a;
    printf("%d ", *b);
}

int comp_items(Item a, Item b) {
    int *a1 = a;
    int *b1 = b;
    return (*a1 - *b1);
}  // Testing lol lol