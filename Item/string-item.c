#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"item.h"

Item in_item(){
    Item a = malloc(sizeof(char *));
    scanf(" %s", a);
    return a;
}

void out_item(Item a){
    char *b = a;
    printf("%s\n", b);
}

int comp_items(Item a, Item b){
    char *a1 = a;
    char *b1 = b;
    return strcmp(a1, b1);
}