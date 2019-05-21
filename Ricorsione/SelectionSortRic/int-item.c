#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item in_item() {
    int *a = malloc(sizeof(int));
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
}

Item fromString(char *str) {
    int *num = malloc(sizeof(int));
    sscanf(str, "%d", num);
    return num;
}