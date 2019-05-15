#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct stack {
    List elements;
};

Stack newStack() {
    Stack stack = malloc(sizeof(struct stack));
    stack->elements = newList();
    return stack;
}

int isEmptyStack(Stack stack) {
    return isEmpty(stack->elements);
}

int push(Stack stack, Item elem) {
    addHead(stack->elements, elem);
    return 1;
}

int pop(Stack stack) {
    return removeHead(stack->elements) == NULL ? 0 : 1;
}

Item top(Stack stack) {
    return getFirst(stack->elements);
}

void printStack(Stack stack) {
    printList(stack->elements);
    printf("\n");
}
