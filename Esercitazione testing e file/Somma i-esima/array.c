#include<stdio.h>
#include<stdlib.h>
#include "utils.h"
#define N 100

int confronta_array(int a[], int b[], int n1, int n2){

	int i;

	if(n1!=n2)
		return 0;

	for(i=0;i<n1;i++)
		if(a[i]!=b[i])
			return 0;

	return 1;

}


void copia_array(int a[], int b[], int n){
	
	int i;
	
	for(i=0;i<n;i++)
		a[i]=b[i];
	
	return;

}


void insert_array(int a[], int *n, int pos, int elem){
/* n è la grandezza/riempimento attuale dell'array, pos è l'indice al quale voglio inserire l'elemento elem*/

	int i;

	for(i=(*n);i>pos;i--)
		a[i]=a[i-1];
	
	a[pos] = elem;
	++*n;

}

void insert_sorted_array(int a[], int *n, int elem){
/* n è la grandezza/riempimento attuale dell'array, pos è l'indice al quale voglio inserire l'elemento elem*/
	
	int i;

	for(i=*n;i>0 && elem<a[i-1];i--)
		a[i]=a[i-1];
	a[i]=elem;
	++*n;

}

int input_array_str(int *arr, char *line){

	int i = 0, numerocifre = 0;

	while(sscanf(line, "%d%n", &arr[i++], &numerocifre)==1) // %n restituisce il numero di caratteri letti fino a quel momento
		line+=numerocifre;

	return i-1;

}

int input_array_str_comma(int *arr, char *line, int *n){

	int i = 0, numerocifre = 0, numerocifretot = 0;

	while(sscanf(line, "%d%n", &arr[*n], &numerocifre)==1){ // %n restituisce il numero di caratteri letti fino a quel momento
		line+=numerocifre;
		numerocifretot+=numerocifre;
		++*n;
	}

	return numerocifretot+1;

}

void input_array(int a[], int n){

	int i;
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

}

void output_array(int a[], int n) {
	
	int i;
	
	for(i=0;i<n;i++) 
		printf("%d ",a[i]);
  	
}

void output_array_infile(int a[], int n, FILE *f) {
	
	int i;
	
	for(i=0;i<n;i++) 
		fprintf(f,"%d ",a[i]);
  	
}

int min(int a[],int n) {
	
	int i, min=0;
	
	for(i=1;i<n;i++) 
		if(a[i]<a[min])
			min=i;
	
	return min;

}

void selection_sort(int a[], int n) {
	
	int i, m;
	
	for(i=0;i<n;i++) {
		m=min(a+i, n-i); //min ritorna un INDICE (l'indice dell'elemento minimo)
		swap(&a[i], &a[m+i]);
	}

}

void insertion_sort(int a[], int n){

	int i = 1;
	while(i<n)
		insert_sorted_array(a, &i, a[i]);
	
}

void bubble_sort(int a[], int n){
	
	int i, j;
	
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1])
				swap(&a[j], &a[j+1]);
	
}

void bubble_sort_adattivo(int a[], int n){
	
	int i, j, ordinato = 0; 
	
	for(i=1;i<n && !ordinato;i++){
		ordinato = 1;
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1]){
				swap(&a[j], &a[j+1]);
				ordinato = 0;
			}
	}
}

void delete_array(int a[], int *n, int pos){
/*n è la grandezza/riempimento attuale dell'array, pos è l'indice dell'elemento da eliminare*/

	int i;
	
	for(i=pos;i<*n;i++)
		a[i] = a[i+1];
	
	--*n;

}

int somma_elementi_array(int a[], int n){

	int i, somma = 0;
	
	for(i=0;i<n;i++)
		somma+=a[i];
	
	return somma;

}

int *somma_dueArray(int a[], int b[], int *n1, int n2, int *flag){

	static int c[N] = {-1};

	if(*n1!=n2){
		c[0]=-1;
		*n1=1;
		return c;
	}
	
	*flag = 1;

	int i;
	
	for(i=0;i<*n1;i++)
		c[i]=a[i]+b[i];
	
	return c;

}

int prodotto_scalare(int a[], int b[], int *n){ // si suppone che i due array abbiano lo stesso riempimento

	int i, sommatot = 0;

	for(i=0;i<*n;i++)
		sommatot = sommatot + (a[i]*b[i]);

	return sommatot;

}

int ricerca_array(int a[], int n, int elem){

	int i;

	for(i=0;i<n && a[i]!=elem;i++);

	return a[i]==elem?i:-1;

}

int ricerca_array_ordinato(int a[], int n, int elem){

	int i;

	for(i=0;i<n && a[i]<elem;i++);

	return a[i]==elem?i:-1;

}

int ricerca_binaria(int a[], int n, int elem){

	int part = 0, fine = n-1;
	
	while(fine>=part){ //se fine < part l'elemento è stato ricercato sia subito prima sia subito dopo dell'i-esimo elemento dell'array ma non c'è stata corrispondenza: esci dal ciclo
		
		int ind_centro = (fine + part) / 2;

		if(a[ind_centro]==elem)
			return ind_centro;
		else if(a[ind_centro]<elem)
			part = ind_centro + 1;
		else if(a[ind_centro]>elem)
			fine = ind_centro - 1;

	}

	return -1;

}


int *input_array_dyn(char *line, int *n){

	*n = conta_spazi(line) + 1;

	int *ptr = (int *)malloc(*n*sizeof(int));

	//ora ptr è un puntatore ad intero (array di interi)

	input_array_str(ptr, line);

	return ptr;

}