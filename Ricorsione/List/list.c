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

int countOccurencies(int i, List list, Item item) {
    if(!list->head) return i;
    if(!comp_items(list->head->value, item)) i++;
    return countOccurencies(i, list->head, item);
}

List cloneListbyPos(List list) {
    List clonelist = newList();

    cloneListRec(0, clonelist, list->head);

    return clonelist;
}

void cloneListRec(int i, List list, struct node *p) {
    if(!p) return;
    if((i % 2) == 1) addHead(list, p->value);
    cloneListRec(++i, list, p->next);
}

Item findMin(List list) {
    return findMinRec(list->head, list->head->value);
}

Item findMinRec(struct node *p, Item item) {
    if(!p) return item;

    if(comp_items(p->value, item) < 0)
        findMinRec(p->next, p->value);
    else
        findMinRec(p->next, item);
}

char *concatene(List list) {
    char str[100];
    str[0] = '\0';
    return concateneRec(str, list->head);
}

char *concateneRec(char *str, struct node *p) {
    if(!p) return str;
    strcat(str, p->value);
    return concateneRec(str, p->next);
}