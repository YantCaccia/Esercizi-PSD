/*Il driver è un .c utilizzato per compilare un programma che testa le funzioni implementate nelle varie librerie*/
#include<stdio.h>
#include "array.h"
#define N 100


int main(void){

    FILE *input = fopen("input_sort.txt", "r");
    FILE *output = fopen("output_sort.txt", "w");
    FILE *oracolo = fopen("oracolo_sort.txt", "r");

    char rigain[50], rigaor[50];
    int arrayditest[N] = {0};
    int arrayoracolo[N] = {0};

    while(fgets(rigain, sizeof(rigain), input)!='\0'&&fgets(rigaor, sizeof(rigaor), oracolo)!='\0'){
        
        int n1 = input_array_str(arrayditest, rigain);
        int n2 = input_array_str(arrayoracolo, rigaor);
        //bubble_sort_adattivo(arrayditest, n1);
        insertion_sort(arrayditest, n1);
        output_array_infile(arrayditest, n1, output);
        if(confronta_array(arrayditest, arrayoracolo, n1, n2)==1)
            fprintf(output, "\tUGUALE\n");
        else
            fprintf(output, "\tDIVERSO\n");
        
    }

    fclose(input);
    fclose(output);
    fclose(oracolo);


    return 0;
}
