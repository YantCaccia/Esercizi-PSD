#include<stdio.h>
#include "array.h"

int main (void){

    char riga[50];
    int n = 0;

    printf("Scrivi i numeri che vuoi inserire nell'array separati da spazi (enter per terminare):\n");
    
    scanf("%[^\n]", riga);
        
    int *a = (int *)input_array_dyn(riga, &n);
    
    insertion_sort(a, n);

    output_array(a, n);

    return 0;

}