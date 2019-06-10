/*Implememtazione con array circolare*/
#include <stdlib.h>
#include "item.h"
#include "queue.h"
#define MAX 10

struct queue {
    Item items[MAX];
    int head;  // indice dell'head
    int tail;  // indice della tail
};

Queue newQueue() {
    Queue queue = malloc(sizeof(struct queue));
    queue->head = 0;
    queue->tail = 0;
}

int isEmptyQueue(Queue queue) {
    if(queue->tail == queue->head)
        return 1;
    else
        return 0;
}

int enqueue(Queue queue, Item item) {
    if((((queue->tail) + 1) % MAX) == queue->head) return 0;

    queue->items[queue->tail] = item;
    queue->tail = ((queue->tail) + 1) % MAX;
    return 1;
}

Item dequeue(Queue queue) {
    int tmp = queue->head;
    queue->head = ((queue->head) + 1) % MAX;
    return queue->items[tmp];
}

void printQueue(Queue queue) {
    for(int i = queue->head; i != queue->tail; i = ((i + 1) % MAX)) {
        out_item(queue->items[i]);
    }
}