#include <stdio.h>
#include <string.h>
#include "esame.h"
#include "item.h"

Item in_item() {
    char nome[30], data[30];
    int voto;

    printf("Nome esame:\n");
    scanf(" %s", nome);
    printf("Data esame:\n");
    scanf(" %s", data);
    printf("Voto esame:\n");
    scanf(" %d", &voto);

    return newExam(nome, data, voto);
}

void out_item(Item esame) {
    Esame exam = esame;
    printf("Nome esame: %s\n", getName(exam));
    printf("Data esame: %s\n", getDate(exam));
    printf("Voto esame: %d\n\n", getMark(exam));
}

int comp_items(Item a, Item b) {
    Esame e1 = a;
    Esame e2 = b;

    return strcmp(getName(e1), getName(e2));
}