#include<stdio.h>
/*Operazioni generiche su un vettore*/
void input_array(int a[], int n); //Riempe un array; n è il numero di elementi che vogliamo inserire
int input_array_str(int *arr, char *line); //Converte una stringa di numeri in array (ritorna il riempimento dell'array)
int *input_array_dyn(char *line, int *n); //Converte una stringa di interi separati da spazi in array allocato dinamicamente e ritorna l'array stesso
int input_array_str_comma(int *arr, char *line, int *n); //Converte una stringa contenente una serie di numeri che termina con "," o "\n" in array (ritorna il riempimento dell'array)
void output_array(int a[], int n); //Stampa in stdout un array
void output_array_infile(int a[], int n, FILE *f); //Come output_array_infile ma stampa in un file
int confronta_array(int a[], int b[], int n1, int n2); //Controlla se due array sono uguali o  diversi
int min(int a[],int n); //Restituisce l'indice dell'elemento più piccolo dell'array; n è il riempimento dell'array
int somma_elementi_array(int a[], int n); //Restituisce la somma degli elementi dell'array in ingresso
int *somma_dueArray(int a[], int b[], int *n1, int n2, int *flag); //Somma a due a due gli elementi i-esimi di due array e restituisce il vettore somma
int prodotto_scalare(int a[], int b[], int *n); //Restituisce il prodotto scalare di due array; n è il riempimento degli array (si suppone che i due array abbiano lo steso riempimento)
void copia_array(int a[], int b[], int n); //Copia b[] in a[]
int ricerca_array(int a[], int n, int elem); //Ricerca un elemento in un array avente riempimento n (scorre tutto l'array finchè non trova l'elemento)
int ricerca_array_ordinato(int a[], int n, int elem); //Ricerca un elemento in un array ordinato (solo nel peggiore dei casi scorre tutto l'array)
int ricerca_binaria(int a[], int n, int elem); //Ricerca binaria per un array ordinato, è più efficiente
/*-----------------------------------*/

/*Operazioni con un solo elemento*/
void insert_array(int a[], int *n, int pos, int elem);
void insert_sorted_array(int a[], int *n, int elem);
void delete_array(int a[], int *n, int pos);
/*-------------------------------*/

/*Ordinamento*/
void selection_sort(int a[], int n);
void insertion_sort(int a[], int n);
void bubble_sort(int a[], int n);
void bubble_sort_adattivo(int a[], int n); //Come il bubble_sort ma si ferma prima se l'array è già ordinato
/*-----------*/