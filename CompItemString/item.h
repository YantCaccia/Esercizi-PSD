typedef void *Item;

Item inputItem();
void outputItem(Item);
int cmpItem(Item, Item);

//funzioni da realizzare

//Istanzia un Item a partire da una stringa
//Dati in ingresso: 
// - str: stringa contenente la descrizione testuale dell'item
//Valore di ritorno: istanza dell'Item
Item fromString(char* str);

//Istanzia un Item a partire da un altro Item, clonando i dati
//Dati in ingresso: 
// - item: Item da clonare
//Valore di ritorno: Item clonato
Item cloneItem(Item item);