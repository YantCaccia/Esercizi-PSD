#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if(isEmpty(list))
        printf("List empty!");
    else
        printListRec(list->head);
}

void printListRec(struct node *p) {
    if(!p) return;
    out_item(p->value);
    printListRec(p->next);
}

Item searchItem(List list, Item item) {
    return searchItemRec(list->head, item);
}

Item searchItemRec(struct node *p, Item item) {
    if(!p) return NULL;  // non trovato

    if(!comp_items(p->value, item))
        return item;  // trovato
    else
        return searchItemRec(p->next, item);  // chiamata ricorsiva
}

void removeAll(List list) {
    removeAllRec(list->head);
    list->head = NULL;
    list->size = 0;
}

void removeAllRec(struct node *p) {
    if(!p->next) {
        free(p);
        return;
    }

    removeAllRec(p->next);
    free(p);
}

int countOccurencies(List list, Item item) {
    return countOccurenciesRec(0, list->head, item);
}

int countOccurenciesRec(int i, struct node *p, Item item) {
    if(!p) return i;
    if(!comp_items(p->value, item)) i++;
    return countOccurenciesRec(i, p->next, item);
}

List cloneListbyPos(List list) {
    return cloneListbyPosRec(0, list->head);
}

List cloneListbyPosRec(int i, struct node *p) {
    if(!p->next) {
        List clonel = newList();
        if(i % 2)
            return addHead(clonel, p->value);
        else
            return clonel;
    }

    if(i % 2)
        return addHead(cloneListbyPosRec(++i, p->next), p->value);
    else
        return cloneListbyPosRec(++i, p->next);
}

Item findMin(List list) {
    return findMinRec(list->head, list->head->value);
}

Item findMinRec(struct node *p, Item item) {
    if(!p->next) return p->value;
    Item a = findMinRec(p->next, item);
    return comp_items(a, p->value) < 0 ? a : p->value;
}

char *concatene(List list) {
    char str[100];
    str[0] = '\0';
    return concateneRec(str, list->head);
}

char *concateneRec(char *str, struct node *p) {
    if(!p->next) return strcat(str, p->value);
    return strcat(concateneRec(str, p->next), p->value);  // FUCKING COOL
}