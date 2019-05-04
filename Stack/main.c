#include<stdio.h>
#include"stack.h"


int main(void){
    Stack stack = newStack();
    
    printf("[%d]\n", isEmptyStack(stack));
    
    printf("Quali elementi vuoi inserire?\n");

    for(int i=0;i<5;i++){
        Item elem = in_item();
        push(stack, elem);
    }

    printStack(stack);
    
    pop(stack);

    printStack(stack);

    printf("[%d]\n", isEmptyStack(stack));

    return 1;
}