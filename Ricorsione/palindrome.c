#include <stdio.h>
#include "string.h"

int palindrome(char *str, int start, int end) {
    if(str[start] != str[end]) return 0;

    if((start == end) || (start == end + 1)) return 1;

    return palindrome(str, start + 1, end - 1);
}

void removeSpaces(char *s) {
    char *p;
    for(p = s; *p != '\0'; p++) {
        if(*p == ' ') {
            for(char *t = p; *t != '\0'; t++) {
                *t = *(t + 1);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char str[50];
    strcpy(str, argv[1]);
    removeSpaces(str);
    printf("%d\n", palindrome(str, 0, (strlen(str) - 1)));
    return 1;
}