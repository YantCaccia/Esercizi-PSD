#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item in_item() {
    char *a = malloc(sizeof(char) * 25);
    scanf(" %s", a);
    return a;
}

void out_item(Item a) {
    char *b = a;
    printf("%s ", b);
}

int comp_items(Item a, Item b) {
    char *a1 = a;
    char *b1 = b;
    return strcmp(a1, b1);
}