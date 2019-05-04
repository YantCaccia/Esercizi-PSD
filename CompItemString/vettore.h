#include"item.h"

int minimo(Item *a, int n);
void selection_sort(Item a[], int n);
void input_array(Item a[], int n);
void output_array(Item *a, int n);

//funzioni da realizzare

//Trasforma una stringa di dati in un vettore di Item
//Dati in ingresso: 
// - line: stringa contenente i dati separati da spazio
// - arr: vettore di Item da riempire
//Valore di ritorno: numero di Item inseriti nel vettore
int input_array_str(Item *arr, char* line);

//Confronta due vettori di Item
//Dati in ingresso: 
// - v1: primo vettore di Item
// - v2: secondo vettore di Item
// - n1: numero di elementi di v1
// - n2: numero di elementi di v2
//Valore di ritorno: 1 se i due vettori sono uguali, 0 altrimenti
int confronta_array(Item v1[], Item v2[],int  n1, int n2);

//Clona un vettore di Item
//Dati in ingresso: 
// - a: vettore di Item
// - n: numero di elementi di a
// - size: taglia del vettore a, modificata dalla funzione
//Valore di ritorno: Il vettore di item clonato. Contiene solo gli elementi pari (con condizione)
Item* cloneEvenItems(Item *a, int n, int *size);