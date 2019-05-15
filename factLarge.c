/*Fattoriale ricorsivo*/
#include <stdio.h>
#include <stdlib.h>
#define N 700

void multiply(int a[], int b, int arr[], int* riemp) {
    int i, respar, resto = 0;
    for(i = 0; i < *riemp; i++) {
        respar = (a[i] * b) + resto;
        arr[i] = (respar % 10);
        resto = respar / 10;
    }
    for(; resto != 0; i++) {
        a[i] = resto % 10;
        resto = resto / 10;
    }
    *riemp = i;
}

void fact(int n) {
    int i = 1;
    int a[N] = {1, 0};
    int riemp = 1;
    for(; i <= n; i++) {
        multiply(a, i, a, &riemp);
    }

    for(i = riemp - 1; i >= 0; i--) printf("%d", a[i]);
    printf("\n");
}

int main(int argc, char* argv[]) {
    fact(atoi(argv[1]));
    return 0;
}