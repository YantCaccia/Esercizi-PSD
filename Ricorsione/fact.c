/*Fattoriale ricorsivo*/
#include <stdio.h>

int fact(int n) {
    if(n != 1)
        return n * fact(n - 1);
    else
        return 1;
}

int main(void) {
    printf("%d\n", fact(5));
    return 0;
}