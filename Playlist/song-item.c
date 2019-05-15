#include <stdio.h>
#include <string.h>
#include "item.h"
#include "song.h"

Item in_item() {
    char autore[20], titolo[20];
    int durata;

    printf("Titolo:\n");
    scanf("%[^\n]", titolo);
    getchar();
    printf("Autore:\n");
    scanf("%[^\n]", autore);
    getchar();
    printf("Durata:\n");
    scanf(" %d", &durata);
    getchar();

    Item a = newSong(titolo, autore, durata);

    return a;
}
void out_item(Item item) {
    char autore[20], titolo[20];
    int durata = getSongDuration(item);

    strcpy(autore, getSongAuthor(item));
    strcpy(titolo, getSongTitle(item));

    printf("Titolo:\n[%s]\n", titolo);
    printf("Autore:\n[%s]\n", autore);
    printf("Durata:\n[%d]\n", durata);
}

int comp_items(Item a, Item b) {
    Song s1 = a;
    Song s2 = b;

    return strcmp(getSongTitle(s1), getSongTitle(s2));
}