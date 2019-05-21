#include <stdio.h>
#include "item.h"
#include "queue.h"
#define nl printf("\n");

Queue invert(Queue q) {
    if(isEmptyQueue(q)) {
        return q;
    }

    Item i = dequeue(q);
    invert(q);
    enqueue(q, i);
}

int main() {
    Queue A = newQueue();

    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());

    printQueue(A);
    nl;

    invert(A);

    printQueue(A);
    nl;

    return 0;
}
