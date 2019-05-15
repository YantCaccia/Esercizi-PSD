#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    Stack stack = newStack();
    char a[100];

    printf("Inserisci in input una stringa:\n");
    scanf(" %s", a);

    for(char *c = a; *c != '\0'; c++) {
        if(*c == '(' || *c == '[' || *c == '{') {
            Item tmp = &c[0];
            push(stack, tmp);
        } else if(*c == ')' || *c == ']' || *c == '}') {
            Item tmp;
            char reallytmp;
            switch(*c) {
                case ')':
                    reallytmp = '(';
                    tmp = &reallytmp;
                    break;
                case ']':
                    reallytmp = '[';
                    tmp = &reallytmp;
                    break;
                case '}':
                    reallytmp = '{';
                    tmp = &reallytmp;
                    break;
            }
            Item pot = top(stack);
            pop(stack);
            if(!comp_items(tmp, pot)) {
                printf("Not balanced!\n");
                exit(1);
            }
        }
    }

    if(isEmptyStack(stack))
        printf("Balanced!\n");
    else
        printf("Not balanced!\n");

    return 1;
}