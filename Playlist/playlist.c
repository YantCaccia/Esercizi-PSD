#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct playlist {
    char nome[20];
    List songs;
};

Playlist newPlaylist(char* nome) {
    Playlist p = malloc(sizeof(struct playlist));
    strcpy(p->nome, nome);
    p->songs = newList();
    return p;
}

Playlist addSong(Playlist playlist, Item item) {
    addHead(playlist->songs, item);
    return playlist;
}

Playlist removeSong(Playlist playlist) {
    printf("Quale canzone vuoi eliminare?\n");
    Item a = in_item();
    removeItemElem(playlist->songs, a);
    return playlist;
}

Playlist sortPlaylist(Playlist playlist) { sortList(playlist->songs); }

void printPlaylist(Playlist playlist) { printList(playlist->songs); }