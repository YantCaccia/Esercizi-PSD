#include "item.h"
typedef struct list *List;

/*removeHead libera il nodo ma non l'item così possiamo usarlo/liberarlo in un secondo momento*/

List newList();
List addHead(List list, Item item);
Item removeHead(List list);
int isEmpty(List list);
void sortList(List list);
void printList(List list);
Item searchItem(List list, Item item);