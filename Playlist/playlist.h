#include "item.h"

typedef struct playlist* Playlist;

Playlist newPlaylist(char* nome);
Playlist addSong(Playlist playlist, Item item);
Playlist removeSong(Playlist playlist);
Playlist sortPlaylist(Playlist playlist);
void printPlaylist(Playlist playlist);