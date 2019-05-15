#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "utils.h"

struct list {
    int size;
    struct node *head;
};

struct node {
    Item value;
    struct node *next;
};

List newList() {
    List lista = malloc(sizeof(struct list));
    lista->head = NULL;
    lista->size = 0;
    return lista;
}

List addHead(List list, Item item) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Item removeHead(List list) {
    if(isEmpty(list)) {
        fprintf(stderr, "List already empty!\n");
        return NULL;
    } else {
        struct node *tempNode = list->head;
        list->head = list->head->next;
        Item tempItem = tempNode->value;
        free(tempNode);
        list->size--;
        return tempItem;
    }
}

Item getFirst(List list) {
    if(isEmpty(list)) {
        fprintf(stderr, "List empty!\n");
        return NULL;
    } else
        return list->head->value;
}

int isEmpty(List list) { return list->head == NULL ? 1 : 0; }

void sortList(List list) {
    if(isEmpty(list))
        fprintf(stderr, "List empty!\n");
    else {
        struct node *i, *j;
        for(i = list->head; i != NULL; i = i->next)
            for(j = list->head; j->next != NULL; j = j->next)  // finisce quando j->next!=NULL perchè all'interno
                                                               // del for ci riferiamo anche a j->next: se fosse
                                                               // NULL darebbe errore.
                if(comp_items(j->value, j->next->value) > 0) swap(&(j->value), &(j->next->value));
    }
    return;
}

void printList(List list) {
    if(isEmpty(list))
        fprintf(stderr, "List empty!\n");
    else {
        struct node *p;
        for(p = list->head; p != NULL; p = p->next) out_item(p->value);
    }
    return;
}

int searchItem(List list, Item item) {
    int i;
    struct node *p = list->head;
    for(i = 0; p != NULL; p = p->next, i++)
        if(!comp_items(p->value, item)) break;
    return i == list->size ? -1 : i;
}

Item removeItemPos(List list, int pos) {
    if(isEmpty(list)) {
        fprintf(stderr, "List already empty!\n");
        return NULL;
    } else if(!pos)
        removeHead(list);
    else {
        struct node *p = list->head;
        for(int i = 0; i < pos - 1; i++, p = p->next)
            ;
        Item tempItem = p->next->value;
        struct node *tmp = p->next;
        p->next = p->next->next;
        free(tmp);
        list->size--;
        return tempItem;
    }
}

Item removeItemElem(List list, Item item) {
    if(isEmpty(list)) {
        fprintf(stderr, "List already empty!\n");
        return NULL;
    } else {
        int pos = searchItem(list, item);
        if(pos == -1)
            fprintf(stderr, "Can't find the item!\n");
        else {
            removeItemPos(list, pos);
        }
    }
}