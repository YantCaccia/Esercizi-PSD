#include<stdio.h>
#include "array.h"
#define N 100

int main (void){

    FILE *input = fopen("input_sommaArray.txt", "r");
    FILE *oracolo = fopen("oracolo_sommaArray.txt", "r");
    FILE *output = fopen("output_sommaArray.txt", "w");

    char str_input[N];
    char str_oracolo[N];

    int n1 = 0, n2 = 0, flag = 0;



    while(fgets(str_input, sizeof(str_input), input)&&fgets(str_oracolo, sizeof(str_oracolo), oracolo)){
        
        int a[N] = {0}, b[N] = {0}, c[N], oracolo[N] = {0};

        n1 = 0; //riempimento di a
        n2 = 0; //riempimento di b
        flag = 0;

        int temp = input_array_str_comma(a, str_input, &n1);
        input_array_str_comma(b, str_input+temp, &n2);

        copia_array(c, somma_dueArray(a, b, &n1, n2, &flag), n1);

        n2 = 0;
        input_array_str_comma(oracolo, str_oracolo, &n2); //n2 non sarà più utilizzata e puo essere sovrascritta (è utilizzata solo all'interno della funzione)

        output_array_infile(c, n1, output);

        if(confronta_array(c, oracolo, n1, n1)==1) //n1 qui indica il riempimento di c (n1 è modificato da somma_dueArray)
            fprintf(output, "UGUALE\n");
        else
            fprintf(output, "DIVERSO\n");


    }


    fclose(input);
    fclose(oracolo);
    fclose(output);


    return 1;
}