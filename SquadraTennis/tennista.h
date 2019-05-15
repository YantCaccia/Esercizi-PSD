typedef struct tennista* Tennista;

char* getName(Tennista tennista);
char* getBirthDate(Tennista tennista);
int getCat(Tennista tennista);
Tennista newTennista(char* nome, char* data, int categoria);