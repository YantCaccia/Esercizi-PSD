#include <stdio.h>
#include "item.h"
#include "playlist.h"
#include "song.h"

int main(void) {
    Playlist p = newPlaylist("Nuova playlist!");
    Item a = in_item();
    Item b = in_item();
    Item c = in_item();
    addSong(p, a);
    addSong(p, b);
    addSong(p, c);
    printf("\n\n\n");
    sortPlaylist(p);
    printPlaylist(p);
    removeSong(p);
    printPlaylist(p);
}