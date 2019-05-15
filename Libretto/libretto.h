#include "esame.h"
#include "item.h"

typedef struct libretto* Libretto;

Libretto newLibretto(char* cognome, char* nome, int matricola);
Libretto addEsame(Libretto, Esame);
Esame cercaEsame(Libretto);
void printLibretto(Libretto);