#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"

Item inputItem() {
	char *p_c;
	p_c = malloc(sizeof(char) * 20);
	
	scanf("%s", p_c);
	
	return p_c;
}


void outputItem(Item it) {

	char *p_c = it;
	
	printf("%s ", p_c);
}

int cmpItem(Item it1, Item it2) {
	char *p_c1 = it1,
		 *p_c2 = it2;
		 
	return strcmp(p_c1, p_c2);
}

//Istanzia un Item a partire da una stringa
//Dati in ingresso: 
// - str: stringa contenente la descrizione testuale dell'item
//Valore di ritorno: istanza dell'Item
Item fromString(char* str){

	char* valoreletto = malloc(sizeof(char)*20);
	int p = sscanf(str, " %s", valoreletto);
	
	if (p!=0)
		return valoreletto;
	else
		return NULL;

}

//Istanzia un Item a partire da un altro Item, clonando i dati
//Dati in ingresso: 
// - item: Item da clonare
//Valore di ritorno: Item clonato
Item cloneItem(Item item){
	Item clone = malloc(sizeof(char)*20);
	char* originale = item;
	sscanf(originale, " %s", clone);
	return clone;
}