#include <stdio.h>
#include "item.h"
#include "queue.h"

Queue get_dispari(Queue oldq, Queue nq) {
    if(isEmptyQueue(oldq)) return nq;
    enqueue(nq, dequeue(oldq));
    dequeue(oldq);
    get_dispari(oldq, nq);
}

int main() {
    Queue A = newQueue();

    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());

    printQueue(A);
    printf("\n");

    Queue B = newQueue();

    get_dispari(A, B);

    printf("Dispari: ");
    printQueue(B);
    printf("\n");

    return 0;
}
