#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "item.h"
#define N 100

int minimo(Item *a, int n) {   
	int min = 0, i;
	
	for(i=1; i<n; i++)
		if (cmpItem(a[i],a[min])<0) 
			min=i;
		
    return min;	
}

void selection_sort(Item a[], int n) {
	int i = 0,
		min;
	
	for(; i < n - 1; i++) {
		min = minimo(a + i, n - i);
		
		swap(&a[i], &a[min + i]);
	}
}

void input_array(Item a[], int n) {
	int i=0;
	
	for (; i<n; i++)
		a[i]=inputItem();
}


void output_array(Item *a, int n) {
	int i;
	
	for(i = 0; i < n; i++)
		outputItem(a[i]);

	printf("\n");
}

//Trasforma una stringa di dati in un vettore di Item
//Dati in ingresso: 
// - line: stringa contenente i dati separati da spazio
// - arr: vettore di Item da riempire
//Valore di ritorno: numero di Item inseriti nel vettore
int input_array_str(Item *arr, char* line){
	
	char sottostringa[10];
	int caratteriletti = 0, caratterilettiora = 0, i = 0;
	
	while(sscanf(line + caratteriletti, " %s%n", sottostringa, &caratterilettiora)!=EOF){
		caratteriletti += caratterilettiora;
		arr[i++] = fromString(sottostringa);
	}
	return i;
	
}

//Confronta due vettori di Item
//Dati in ingresso: 
// - v1: primo vettore di Item
// - v2: secondo vettore di Item
// - n1: numero di elementi di v1
// - n2: numero di elementi di v2
//Valore di ritorno: 1 se i due vettori sono uguali, 0 altrimenti
int confronta_array(Item v1[], Item v2[],int  n1, int n2){
	
	if(n1!=n2) return 0;

	for(int i = 0;i<n1;i++)
		if(cmpItem(v1[i], v2[i]))
			return 0;

	return 1;
}

//Clona un vettore di Item
//Dati in ingresso: 
// - a: vettore di Item
// - n: numero di elementi di a
// - size: taglia del vettore a, modificata dalla funzione
//Valore di ritorno: Il vettore di item clonato. Contiene solo gli elementi pari (con condizione)
Item* cloneEvenItems(Item *a, int n, int *size){
	
	Item *clone = malloc(sizeof(char)*(n/2));
	int j=0;

	for(int i=1;i<n;i=i+2)
		if(cmpItem(a[i], a[i-1])>0)
			clone[j++]=a[i];

	*size = j;

	return clone;

}