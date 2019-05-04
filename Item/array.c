#include<stdio.h>
#include "utils.h"


void input_array(Item* a, int n){
	for(int i = 0;i<n;i++){
        a[i] = in_item();
    }
}

void output_array(Item* a, int n) {
	for(int i = 0;i<n;i++){
        out_item(a[i]);
    }
}

void bubble_sort(Item* a, int n){
	
	int i, j;
	
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(comp_items(a[j], a[j+1])>0) //da modificare per renderlo compatibile con tutti i tipi rappresentati da Item
				swap(&a[j], &a[j+1]);
	
}