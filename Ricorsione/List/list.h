#include "item.h"
typedef struct list *List;
typedef struct node *Node;

/*removeHead libera il nodo ma non l'item così possiamo usarlo/liberarlo in un secondo momento*/

List newList();
List addHead(List list, Item item);
Item removeHead(List list);
Item getFirst(List list);
int isEmpty(List list);
void sortList(List list);
void printList(List list);
void printListRec(struct node *p);
List insertTail(List list, Item item);
List insertItem(List list, Item item, int pos);
List reverseList(List list);
List cloneList(List list);
Item searchItem(List list, Item item);
Item searchItemRec(struct node *p, Item item);
Item removeItemPos(List list, int pos);
Item removeItemElem(List list, Item item);
void removeAll(List list);
void removeAllRec(struct node *p);
int countOccurencies(List list, Item item);
int countOccurenciesRec(int i, struct node *p, Item item);
List cloneListbyPos(List list);
List cloneListbyPosRec(int i, struct node *p);
Item findMin(List list);
Item findMinRec(struct node *p, Item item);
char *concatene(List list);
char *concateneRec(char *str, struct node *p);
