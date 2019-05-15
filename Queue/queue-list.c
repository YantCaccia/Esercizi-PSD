#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "queue.h"

struct queue {
    List items;
};

Queue newQueue() {
    Queue queue = malloc(sizeof(struct queue));
    queue->items = newList();
}

int isEmptyQueue(Queue queue) {
    return isEmpty(queue->items);
}

int enqueue(Queue queue, Item item) {
    insertTail(queue->items, item);
    return 1;
}

Item dequeue(Queue queue) {
    return removeHead(queue->items);
}

void printQueue(Queue queue) {
    printList(queue->items);
}
