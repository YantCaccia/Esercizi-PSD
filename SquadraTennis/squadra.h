#include "list.h"
#include "tennista.h"

typedef struct squadra* Squadra;

Squadra newSquadra(char* nome, char* indirizzo, int num);
Squadra inTennista(Squadra squadra, Tennista tennista);
Squadra outTennista(Squadra squadra, int pos);
Squadra forwardTennista(Squadra squadra, int pos);
List cloneTennistsByCategory(Squadra squadra, int cat);
void printSquadra(Squadra squadra);