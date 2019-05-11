#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "utils.h"

struct list {
    int size;
    struct node *head;
    struct node *tail;
};

struct node {
    Item value;
    struct node *next;
};

List newList() {
    List lista = malloc(sizeof(struct list));
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

Item removeHead(List list) {
    if(isEmpty(list))
        return NULL;
    else {
        struct node *tempNode = list->head;
        list->head = list->head->next;
        Item tempItem = tempNode->value;
        free(tempNode);
        list->size--;
        if(isEmpty(list)) list->tail == NULL;
        return tempItem;
    }
}

Item getFirst(List list) {
    if(isEmpty(list))
        return NULL;
    else
        return list->head->value;
}

int isEmpty(List list) {
    return list->head == NULL ? 1 : 0;
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

List insertTail(List list, Item item) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = NULL;

    if(isEmpty(list)) {
        list->head = newNode;
    }

    else {
        list->tail->next = newNode;
    }

    list->tail = newNode;
    list->size++;

    return list;
}