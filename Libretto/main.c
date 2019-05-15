#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "libretto.h"

int main(void) {
    char cognome[30], nome[30];
    int mat, codop;

    printf("Inserisci cognome:\n");
    scanf(" %s", cognome);

    printf("Inserisci nome:\n");
    scanf(" %s", nome);

    printf("Inserisci matricola:\n");
    scanf(" %d", &mat);

    Libretto lib = newLibretto(cognome, nome, mat);

    while(1) {
        getchar();
        printf("\n1.Aggiungi un esame\n2.Cerca un esame\n3.Stampa libretto\n0.Esci\n");
        scanf(" %d", &codop);
        switch(codop) {
            case 1: {
                Item exam = in_item();
                addEsame(lib, exam);
                break;
            }
            case 2:
                out_item(cercaEsame(lib));
                break;
            case 3:
                printLibretto(lib);
                break;
            case 0:
                exit(1);
            default:
                fprintf(stderr, "Invalid OP Code!\n");
                break;
        }
    }

    return 1;
}