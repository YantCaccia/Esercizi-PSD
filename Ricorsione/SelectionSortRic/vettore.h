#include "item.h"

int minimo(Item *a, int n);
void selection_sort(Item a[], int n);
void input_array(Item a[], int n);
void output_array(Item *a, int n);
int input_array_str(Item *arr, char *line);
int confronta_array(Item v1[], Item v2[], int n1, int n2);
Item *cloneEvenItems(Item *a, int n, int *size);
void selection_sort_ric(Item a[], int n);