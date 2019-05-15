/*Funzione ricorsiva che stampa il reverse di una stringa*/
#include <stdio.h>

void printReverse(char *s) {
    if(*(s + 1) != '\0') printReverse(s + 1);
    printf("%c", *s);
}

int main(int argc, char *argv[]) {
    printReverse(argv[1]);
    printf("\n");
    return 0;
}