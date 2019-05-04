#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item in_item() {
    Item a = malloc(sizeof(char));
    scanf(" %c", a);
    return a;
}

void out_item(Item a) {
    char *b = a;
    printf("%c\n", *b);
}

int comp_items(Item a, Item b) {
    char *a1 = a;
    char *b1 = b;

    return *a1 == *b1 ? 1 : 0;
}