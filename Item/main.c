#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"array.h"

int main(void){

    int n;

    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &n);

    Item* arr = malloc(n*sizeof(Item));

    printf("Inserisci gli elementi da inserie nell'array:\n");

    input_array(arr, n);

    printf("\nArray non ordinato:\n");
    output_array(arr, n);

    bubble_sort(arr, n);

    printf("\n\nArray ordinato:\n");
    output_array(arr, n);

    printf("\n\nCiao!\n");



    return 0;
}