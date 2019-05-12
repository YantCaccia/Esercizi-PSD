#include <stdio.h>
#include "list.h"

int main(void) {
    List list = newList();
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());
    addHead(list, in_item());

    // printList(list);
    // removeAll(list);
    printList(list);
    printf("\n");

    int *p = searchItem(list, in_item());
    
    if(p)
        printf("%d\n", *p);
    else
        printf("Not found!\n");

    return 0;
}