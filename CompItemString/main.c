#include <stdio.h>
#include "vettore.h"
#include "item.h"




int main(){
	int i, n = 6, size;
	Item arr[n], *clone;
	printf("Introduci il vettore: ");
	input_array(arr, n);
	clone = cloneEvenItems(arr, n, &size);
	printf("Clone: ");
	output_array(clone, size);
}