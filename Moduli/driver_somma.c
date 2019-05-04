#include<stdio.h>
#include "array.h"

int main (void){

    FILE *input = fopen("input_somma.txt", "r");
    FILE *oracolo = fopen("oracolo_somma.txt", "r");
    FILE *output = fopen("output_somma.txt", "w");

    char str_input[100];
    char str_oracolo[100];

    int array_input[100];
    int numero_oracolo;

    while(fgets(str_input, sizeof(str_input), input)&&fgets(str_oracolo, sizeof(str_oracolo), oracolo)){
        
        int n = input_array_str(array_input, str_input);
        sscanf(str_oracolo, "%d", &numero_oracolo);

        int somma = somma_elementi_array(array_input, n);

        fprintf(output, "%d", somma);

        if(numero_oracolo==somma)
            fprintf(output, "\tUguale\n");
        else
            fprintf(output, "\tDiverso\n");
                
    }

    fclose(input);
    fclose(oracolo);
    fclose(output);

    return 1;
}