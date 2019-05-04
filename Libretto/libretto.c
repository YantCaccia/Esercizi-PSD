#include "libretto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esame.h"
#include "list.h"

struct libretto {
    char cognome[20];
    char nome[20];
    int matricola;
    List exams;
};

Libretto newLibretto(char* cognome, char* nome, int matricola) {
    Libretto libretto = malloc(sizeof(struct libretto));
    strcpy(libretto->cognome, cognome);
    strcpy(libretto->nome, nome);
    libretto->matricola = matricola;
    libretto->exams = newList();
    return libretto;
}

Libretto addEsame(Libretto libretto, Esame exam) {
    Item item = exam;
    addHead(libretto->exams, item);
    return libretto;
}

Esame cercaEsame(Libretto libretto) {
    char examname[30];
    printf("Che esame vuoi cercare?\n");
    scanf(" %[^\n]", examname);
    Esame exam = newExam(examname, "", 0);

    return searchItem(libretto->exams, exam);
}

void printLibretto(Libretto libretto) {
    printf("Cognome: %s\n", libretto->cognome);
    printf("Nome: %s\n", libretto->nome);
    printf("Matricola: %d\n", libretto->matricola);

    printList(libretto->exams);
}