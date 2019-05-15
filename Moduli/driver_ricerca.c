#include<stdio.h>
#include "array.h"
#define N 100


int main(void){

    FILE *input = fopen("input_ricerca.txt", "r");

    char rigain[50];
    int arrayditest[N] = {0};
    int elem;

    while(fgets(rigain, sizeof(rigain), input)!='\0'){
        
        int n1 = input_array_str(arrayditest, rigain);

        printf("Quale elemento vuoi cercare?\n");

        scanf("%d", &elem);

        int risultato = ricerca_binaria(arrayditest, n1, elem);

        printf("Risultato della chiamata: [%d]\n", risultato);    
        
    }

    fclose(input);

    return 0;
}