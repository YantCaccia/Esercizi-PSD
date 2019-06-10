/*Produce un ordinamento partendo da un vettore utilizzando un BST*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char* argv[]) {
    List nlist = newList();
    char* a[5] = {"ciao", "come", "va", "la", "vita"};
    for(int i = 0; i < 5; i++) {
        char* tmp = malloc(sizeof(char*) * 10);
        strcpy(tmp, a[i]);
        insertTail(nlist, tmp);
    }

    printf("[%s]\n", concatena(nlist));
}