#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#define N 50

int main (int argc, char *argv[]){

    if(argc!=4){
        fprintf(stderr, "Usage: driver.exe INPUTFILE ORACOLO OUTPUTFILE\n");
        exit(1);
    }

    FILE *f_in;
    FILE *f_out;
    FILE *f_or;

    if((f_in = fopen(argv[1], "r"))==NULL){
        fprintf(stderr, "Error opening %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((f_or = fopen(argv[2], "r"))==NULL){
        fprintf(stderr, "Error opening %s", argv[2]);
        exit(EXIT_FAILURE);
    }

    if((f_out = fopen(argv[3], "w"))==NULL){
        fprintf(stderr, "Error opening %s", argv[3]);
        exit(EXIT_FAILURE);
    }

    char lineinput[N], lineor[N];

    while(fgets(lineinput, sizeof(lineinput), f_in)!='\0'&&fgets(lineor, sizeof(lineor), f_or)!='\0'){
        
        int arr1[N], arr2[N], arr_or[N];

        int n1 = 0, n2 = 0, n_or = input_array_str(arr_or, lineor);

        int temp = input_array_str_comma(arr1, lineinput, &n1);
        input_array_str_comma(arr2, lineinput + temp, &n2);

        printf("n1:[%d] n2:[%d]\n", n1, n2);

        int flag = 0; //(?)

        int sommai[N];
        
        copia_array(sommai, somma_dueArray(arr1, arr2, &n1, n2, &flag), n1);

        output_array_infile(sommai, n1, f_out);

        if(confronta_array(sommai, arr_or, n1, n_or)==1)
            fprintf(f_out, "Uguali\n");
        else
            fprintf(f_out, "Diversi\n");

    }


    return 1;
}