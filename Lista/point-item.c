#include<stdlib.h>
#include<stdio.h>
#include"point.h"
#include"item.h"

Item in_item(){
    Item a = malloc(sizeof(Point));
    float x, y;
    printf("\nAscissa: ");
    scanf("%f", &x);
    printf("Ordinata: ");
    scanf("%f", &y);
    return makepoint(x, y);
}

void out_item(Item a){
    Point b = a;
    printf("(%.1f;%.1f)\n", ascissa(b), ordinata(b));
}

int comp_items(Item a, Item b){
    Point origine = makepoint(0, 0);
    float dist1 = distanza(a, origine);
    float dist2 = distanza(b, origine);

    return dist1 - dist2;

}