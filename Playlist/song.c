#include "song.h"
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct song {
    char titolo[20];
    char autore[20];
    int durata;
};

Song newSong(char* titolo, char* autore, int durata) {
    Song song = malloc(sizeof(struct song));

    strcpy(song->autore, autore);
    strcpy(song->titolo, titolo);
    song->durata = durata;

    return song;
}
char* getSongTitle(Item song) {
    Song s = song;
    return s->titolo;
}
char* getSongAuthor(Item song) {
    Song s = song;
    return s->autore;
}
int getSongDuration(Item song) {
    Song s = song;
    return s->durata;
}