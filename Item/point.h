/*Nel .h utilizziamo la typedef con puntatore per non rendere visibili e direttamente accessibili i campi della struttura nel main.c
In questo modo il client è costretto ad utilizzare le funzioni da noi specificate nel .h ed implementate nel .c*/

/*ALTERNATIVA*/
/*Se non siamo interessati all'information hiding implentiamo la struttura direttamente nel .h:

typedef struct{
    ..
} NOMESTRUTTURA;

*/

typedef struct point* Point; //point è un PUNTATORE alla struttura di tipo point definita nel .c

float ascissa(Point p);
float ordinata(Point p);
float distanza(Point p1, Point p2);
Point spostapunto(Point p, float x, float y);
Point centroide(Point a[], int m); //m è il riempimento
Point makepoint(float x, float y);