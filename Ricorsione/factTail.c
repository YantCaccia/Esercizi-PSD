/*Funzione che calcola il fattoriale di N implementata con metodo di Ricorsione Tail*/
#include <stdio.h>

int factInt(int n, int parziale, int contatore) {
    if(contatore <= n) {
        parziale = parziale * contatore;
        contatore++;
        return factInt(n, parziale, contatore);
    }
    return parziale;
}

int fact(int n) {
    return factInt(n, 1, 1);
}

int main(void) {
    printf("%d\n", fact(5));
    return 0;
}