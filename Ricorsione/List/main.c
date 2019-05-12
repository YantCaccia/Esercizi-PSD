#include <stdio.h>
#include "list.h"

int main(void) {
    List list = newList();
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());

    // printList(list);
    // removeAll(list);
    printList(list);
    printf("\n");

    int i = countOccurencies(0, list, in_item());

    printf("%d\n", i);

    return 0;
}