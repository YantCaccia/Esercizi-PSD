#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mcd(int a, int b);

int main(int argc, char* argv[]) {
    printf("sono gay (metti la password al pc) %d\n", mcd(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

int mcd(int a, int b) {
    if(b == 0) return a;
    return mcd(b, a % b);
}