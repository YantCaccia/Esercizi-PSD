#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#define N 15

int main (int argc, char *argv[]){

    if(argc!=4){
        fprintf(stderr, "Usage: driver_somma.c INPUTFILE ORACOLO OUTPUTFILE\n");
        exit(1);
    }



    FILE *f_in = fopen(argv[1], "r");
    FILE *f_or = fopen(argv[2], "r");
    FILE *f_out = fopen(argv[3], "w");

    char lineinput[N], lineoracolo[N];

    while(fgets(lineinput, sizeof(lineinput), f_in)&&fgets(lineoracolo, sizeof(lineoracolo), f_or)){

        int arrayin[N], arrayor[1];

        int n1 = input_array_str(arrayin, lineinput); //n1 è il riempimento dell'array che contiene i numeri da sommare

        int n2 = input_array_str(arrayor, lineoracolo);

        int somma = somma_elementi_array(arrayin, n1);

        output_array_infile(arrayin, n1, f_out);
        output_array_infile(arrayor, n2, f_out);

        if(somma==arrayor[0])
            fprintf(f_out, "Uguali\n");
        else
            fprintf(f_out, "Diversi\n");
    }




    return 1;
}