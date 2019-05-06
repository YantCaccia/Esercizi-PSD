#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

struct queue {
    Stack s1;
    Stack s2;
};

Queue newQueue() {
    Queue queue = malloc(sizeof(struct queue));
    queue->s1 = newStack();
    queue->s2 = newStack();

    return queue;
}

int isEmptyQueue(Queue queue) {
    if(isEmptyStack(queue->s1) && isEmptyStack(queue->s2))
        return 1;
    else
        return 0;
}

int enqueue(Queue queue, Item item) {
    push(queue->s1, item);
    return 1;
}

Item dequeue(Queue queue) {
    if(isEmptyQueue(queue)) {
        printf("Error: Queue is empty!\n");
        return NULL;
    }
    if(isEmptyStack(queue->s2)) {
        for(Item a = top(queue->s1); a != NULL; a = top(queue->s1)) {
            push(queue->s2, a);
            pop(queue->s1);
        }
    }

    Item a = top(queue->s2);
    pop(queue->s2);
    return a;
}

void printQueue(Queue queue) {
    if(!isEmptyStack(queue->s1)) printStack(queue->s1);
    if(!isEmptyStack(queue->s2)) printStack(queue->s2);
    return;
}