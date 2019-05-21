#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "utils.h"
#define N 100

int minimo(Item *a, int n) {
    int min = 0, i;

    for(i = 1; i < n; i++)
        if(comp_items(a[i], a[min]) < 0) min = i;

    return min;
}

void selection_sort(Item a[], int n) {
    int i = 0, min;

    for(; i < n - 1; i++) {
        min = minimo(a + i, n - i);

        swap(&a[i], &a[min + i]);
    }
}

void input_array(Item a[], int n) {
    int i = 0;

    for(; i < n; i++) a[i] = in_item();
}

void output_array(Item *a, int n) {
    int i;

    for(i = 0; i < n; i++) out_item(a[i]);

    printf("\n");
}

int input_array_str(Item *arr, char *line) {
    char sottostringa[10];
    int caratteriletti = 0, caratterilettiora = 0, i = 0;

    while(sscanf(line + caratteriletti, " %s%n", sottostringa, &caratterilettiora) != EOF) {
        caratteriletti += caratterilettiora;
        arr[i++] = fromString(sottostringa);
    }
    return i;
}

int confronta_array(Item v1[], Item v2[], int n1, int n2) {
    if(n1 != n2) return 0;

    for(int i = 0; i < n1; i++)
        if(comp_items(v1[i], v2[i])) return 0;

    return 1;
}

Item *cloneEvenItems(Item *a, int n, int *size) {
    Item *clone = malloc(sizeof(char) * (n / 2));
    int j = 0;

    for(int i = 1; i < n; i = i + 2)
        if(comp_items(a[i], a[i - 1]) > 0) clone[j++] = a[i];

    *size = j;

    return clone;
}

void selection_sort_ric(Item a[], int n) {
    if(n == 0) return;

    int min = minimo(a, n);
    swap(&a[0], &a[min]);
    selection_sort_ric(a + 1, n - 1);
}