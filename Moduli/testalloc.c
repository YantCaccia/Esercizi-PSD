#include<stdio.h>
#include<stdlib.h>
#include "array.h"

int main (void){

    char opcod;
    int num, riemp = 0;

    int *a = (int *)malloc(riemp*sizeof(int));

    while(1){


        printf("Cosa vuoi fare?\n'I' per inserire un elemento\n'P' per stampare l'array\n'O' per ordinare l'array\n'Q' per uscire\n");
        scanf(" %c", &opcod);
        getchar();

        switch (opcod) {
            case 'q': exit(1);

            case 'o': bubble_sort(a, riemp);
                      break;

            case 'i': printf("Quale numero vuoi inserire?\n");
                      scanf(" %d", &num);
                      ++riemp;
                      a = realloc(a, riemp*sizeof(int));
                      a[riemp-1]=num;                      
                      break;

            case 'p': for(int *pt = a;pt<a+riemp;pt++)
                        printf("%d ", *pt);
                      printf("\n");
                      break;
            
        }


    }







    return 0;
}