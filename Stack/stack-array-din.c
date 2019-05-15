#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define START_DIM 4
#define ADD_DIM 3

// implement dim

struct stack {
    // Item elements[START_DIM];
    Item *elements;
    int top;
    int dim;
};

Stack newStack() {
    Stack newStack = malloc(sizeof(struct stack));
    newStack->elements = malloc(START_DIM * sizeof(Item));
    newStack->top = 0;
    newStack->dim = START_DIM;

    return newStack;
}

int isEmptyStack(Stack stack) {
    return !stack->top;
}

int push(Stack stack, Item item) {
    if(stack->top == stack->dim) {
        realloc(stack->elements, ADD_DIM * sizeof(Item));
        stack->dim += ADD_DIM;
    }

    stack->elements[stack->top] = item;
    stack->top++;

    return 1;
}

int pop(Stack stack) {
    if(isEmptyStack(stack)) return 0;

    stack->top--;
    return 1;
}

Item top(Stack stack) {
    if(isEmptyStack(stack)) return NULL;

    return stack->elements[stack->top - 1];
}

void printStack(Stack stack) {
    int i;
    printf("TOP: ");

    for(i = stack->top - 1; i >= 0; i--) out_item(stack->elements[i]);

    printf("\n[%d]", stack->dim);
}