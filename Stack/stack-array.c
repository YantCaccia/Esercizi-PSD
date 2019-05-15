#define FIXED_DIM 10
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

struct stack {
    Item arr[FIXED_DIM];
    int riemp;
};

Stack newStack() {
    Stack stack = malloc(sizeof(struct stack));
    stack->riemp = 0;
    return stack;
}

int isEmptyStack(Stack stack) { return !stack->riemp; }

int push(Stack stack, Item item) {
    if(stack->riemp == FIXED_DIM) {
        printf("Reached maximum dimesion of the stack!\n");
        return 0;
    } else
        stack->arr[stack->riemp++] = item;
    return 1;
}

int pop(Stack stack) { free(stack->arr[stack->riemp--]); }

Item top(Stack stack) {
    if(isEmptyStack(stack)) {
        printf("Empty stack!");
    } else
        return stack->arr[stack->riemp];
}

void printStack(Stack stack) {
    if(isEmptyStack(stack)) {
        printf("Empty stack!");
    } else {
        for(int i = stack->riemp - 1; i >= 0; i--) out_item(stack->arr[i]);
        printf("\n");
    }
}