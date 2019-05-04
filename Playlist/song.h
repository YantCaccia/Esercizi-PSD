#include "item.h"

typedef struct song* Song;

Song newSong(char* titolo, char* autore, int durataItem);
char* getSongTitle(Item song);
char* getSongAuthor(Item song);
int getSongDuration(Item song);