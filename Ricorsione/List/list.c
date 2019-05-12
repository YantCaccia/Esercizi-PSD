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
    return list;
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

int isEmpty(List list) {
    return list->head == NULL ? 1 : 0;
}

void printList(List list) {
    if(!list->head) return;
    out_item(list->head->value);
    printList(list->head);  // NON SO PERCHE' CAZZO FUNZIONI (DOVREI PASSARE ->NEXT)
}

Item searchItem(List list, Item item) {
    if(!list->head) return NULL;  // non trovato

    if(!comp_items(list->head->value, item))
        return item;  // trovato
    else
        return searchItem(list->head, item);  // chiamata ricorsiva
}

void removeAll(List list) {
    if(!list->head->next) {
        free(list->head);
        return;
    }

    removeAll(list->head);
    free(list->head);
    list->head = NULL;
    list->size--;
}
