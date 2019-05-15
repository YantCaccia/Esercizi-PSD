#include <stdio.h>
#include "item.h"
#include "queue.h"

int main() {
    Queue A = newQueue();

    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());

    printQueue(A);
    printf("Fine prima queue\n");

    enqueue(A, in_item());
    enqueue(A, in_item());

    printQueue(A);
    printf("Fine seconda queue\n");

    dequeue(A);
    dequeue(A);
    dequeue(A);
    dequeue(A);
    dequeue(A);
    dequeue(A);
    dequeue(A);  // 7a dequeue per testare il suo funzionamento quando la Queue passata è già vuota

    printQueue(A);
    printf("Fine terza queue\n");

    enqueue(A, in_item());
    enqueue(A, in_item());
    printQueue(A);
    printf("Fine quarta queue\n");

    return 0;
}
