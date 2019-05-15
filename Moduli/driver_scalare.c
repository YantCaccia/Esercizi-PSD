#include<stdio.h>
#include "array.h"
#define N 100

int main (void){

    FILE *input = fopen("input_scalare.txt", "r");
    FILE *oracolo = fopen("oracolo_scalare.txt", "r");
    FILE *output = fopen("output_scalare.txt", "w");

    char str_input[N];
    char str_oracolo[N];

    int n1 = 0, n2 = 0, prodotto_oracolo;



    while(fgets(str_input, sizeof(str_input), input)&&fgets(str_oracolo, sizeof(str_oracolo), oracolo)){
        
        int a[N] = {0}, b[N] = {0};

        n1 = 0; //riempimento di a
        n2 = 0; //riempimento di b

        int temp = input_array_str_comma(a, str_input, &n1);
        input_array_str_comma(b, str_input+temp, &n2);

        int prodotto = prodotto_scalare(a, b, &n1);

        sscanf(str_oracolo, "%d", &prodotto_oracolo);

        fprintf(output, "%d\t", prodotto);

        if(prodotto==prodotto_oracolo) //n1 qui indica il riempimento di c (n1 è modificato da somma_dueArray)
            fprintf(output, "UGUALE\n");
        else
            fprintf(output, "DIVERSO\n");


    }


    fclose(input);
    fclose(oracolo);
    fclose(output);


    return 1;
}