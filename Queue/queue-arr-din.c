/*Implememtazione con array circolare allocato dinamicamente*/
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct queue {
    Item *items;
    int head;  // indice dell'head
    int tail;  // indice della tail
    int max;   // capacità dell'array (cambia durante l'esecuzione)
};

Queue newQueue() {
    Queue queue = malloc(sizeof(struct queue));
    queue->head = 0;
    queue->tail = 0;
    queue->max = 5;
    queue->items = malloc(sizeof(Item) * queue->max);
}

int isEmptyQueue(Queue queue) {
    if(queue->tail == queue->head)
        return 1;
    else
        return 0;
}

int enqueue(Queue queue, Item item) {
    if(((queue->tail + 1) % queue->max) == queue->head) {  // Se l'array è pieno
        int i;
        queue->items = realloc(queue->items, sizeof(Item) * 2 * queue->max);  // 1.Amplio l'array raddoppiandolo

        /* 2.Sposto tutti gli elementi di indice compreso tra 0 e TAIL nelle celle*/
        /* aventi indice maggiore di HEAD (allocate al passo 1) ----------------- */
        for(i = 0; i < queue->tail; i++) {
            queue->items[i + queue->max] = queue->items[i];
        }

        queue->tail = i;                // 3.Aggiorno TAIL
        queue->max = 2 * (queue->max);  // 4.Aggiorno MAX
    }

    /* ---------------------------------- */

    queue->items[queue->tail] = item;
    queue->tail = ((queue->tail) + 1) % queue->max;
    return 1;
}

Item dequeue(Queue queue) {
    if(isEmptyQueue(queue)) return NULL;
    int tmp = queue->head;
    queue->head = ((queue->head) + 1) % queue->max;
    return queue->items[tmp];
}

void printQueue(Queue queue) {
    for(int i = queue->head; i != queue->tail; i = ((i + 1) % queue->max)) {
        out_item(queue->items[i]);
    }
}