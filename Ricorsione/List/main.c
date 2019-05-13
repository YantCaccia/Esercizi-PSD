#include <stdio.h>
#include "list.h"
#define nl printf("\n")

int main(void) {
    List list = newList();
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());

    printList(list);
    nl;

    printf("[%d]\n", countOccurencies(list, in_item()));
    nl;

    return 0;
}