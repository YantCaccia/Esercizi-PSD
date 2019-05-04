#include<stdio.h>
#include<stdlib.h>
#include "vettore.h"

#define N 50

int main(void)
{
	FILE *fp_input, *fp_oracolo, *fp_output;
	
	if((fp_input=fopen("input.txt", "r"))==NULL){
		fprintf(stderr, "Errore apertura file input.txt\n");
		exit(EXIT_FAILURE);
	}
	
	if((fp_oracolo=fopen("oracolo.txt", "r"))==NULL){
		fprintf(stderr, "Errore apertura file oracolo.txt\n");
		exit(EXIT_FAILURE);
	}
	
	if((fp_output=fopen("output.txt", "w"))==NULL){
		printf("Errore apertura file output.txt\n");
		exit(EXIT_FAILURE);
	}

	char lineinput[50], lineoracolo[20];
	Item arr[50], arr2[20];

	while(fscanf(fp_input, "%[^\n]", lineinput)!=EOF&&fscanf(fp_oracolo, "%[^\n]", lineoracolo)!=EOF){
		int size = 0;

		int riemp1 = input_array_str(arr, lineinput);

		Item *clone = cloneEvenItems(arr, riemp1, &size);

		int riemp2 = input_array_str(arr2, lineoracolo);

		if(confronta_array(arr2, clone, riemp2, size)==1)
			fprintf(fp_output, "Uguali\n");
		else
			fprintf(fp_output, "Non uguali\n");
	}
	
	fclose(fp_input);
	fclose(fp_output);
	fclose(fp_oracolo);
	
	return 0;
		
}