#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List); 

Item searchList(List, Item, int*);
Item removeItem(List, Item);
Item removePos(List, int);
int addItem(List list, Item, int pos); // 0 <= pos <= sizeList(list)
int addTail(List, Item);
void reverseList(List);
List cloneList(List);
