#include "esame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct esame {
    char name[30];
    int mark;
    char date[30];
};

Esame newExam(char *nome, char *data, int voto) {
    Esame esame = malloc(sizeof(struct esame));
    strcpy(esame->name, nome);
    strcpy(esame->date, data);
    esame->mark = voto;

    return esame;
}

char *getName(Esame esame) {
    return esame->name;
}
int getMark(Esame esame) {
    return esame->mark;
}
char *getDate(Esame esame) {
    return esame->date;
}