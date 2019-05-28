#include <stdio.h>

void merge(int a[], int n1, int b[], int n2, int c[]) {
    int i, j, k = 0;
    int d[n1 + n2];
    for(i = 0, j = 0; i < n1 && j < n2; k++)
        if(a[i] <= b[j])
            d[k] = a[i++];
        else
            d[k] = b[j++];

    if(i == n1 && j != n2)
        for(; j < n2; j++, k++) d[k] = b[j];
    else if(i != n1 && j == n2)
        for(; i < n1; i++, k++) d[k] = a[i];

    for(int i = 0; i < n1 + n2; i++) c[i] = d[i];
}

void mergesort(int arr[], int n) {
    if(n > 2) {
        mergesort(arr, n / 2);
        mergesort(arr + n / 2, n - n / 2);
    }
    merge(arr, n / 2, arr + n / 2, n - n / 2, arr);
}

int main(void) {
    int a[] = {23, 5, -5, -7, 0, 3, 11, 4};
    int n = sizeof(a) / sizeof(int);

    mergesort(a, n);

    for(int i = 0; i < n; i++) printf("[%d] ", a[i]);

    return 0;
}