#include <stdio.h>
#include "item.h"
#include "queue.h"

int main() {
    Queue A = newQueue();

    enqueue(A, in_item());
    enqueue(A, in_item());
    enqueue(A, in_item());

    printQueue(A);
    printf("Fine prima queue\n");

    dequeue(A);
    dequeue(A);

    printQueue(A);
    printf("Fine seconda queue\n");

    enqueue(A, in_item());

    printQueue(A);
    printf("Fine terza queue\n");

    return 0;
}
