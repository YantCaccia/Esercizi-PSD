#include <stdio.h>
#include "list.h"
#define newline printf("\n")

int main(void) {
    List list = newList();
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());

    printList(list);
    newline;

    printf("Final string: [%s]\n", concatene(list));

    return 0;
}