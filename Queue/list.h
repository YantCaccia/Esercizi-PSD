#include "item.h"
typedef struct list *List;

/*removeHead libera il nodo ma non l'item così possiamo usarlo/liberarlo in un secondo momento*/

List newList();
Item removeHead(List list);
Item getFirst(List list);
int isEmpty(List list);
void printList(List list);
List insertTail(List list, Item item);