/*Fattoriale ricorsivo*/
#include <stdio.h>
#include <stdlib.h>

int fact(int n) {
    if(n != 1)
        return n * fact(n - 1);
    else
        return 1;
}

int main(int argc, char* argv[]) {
    printf("%d\n", fact(atoi(argv[1])));
    return 0;
}