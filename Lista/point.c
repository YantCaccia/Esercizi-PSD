#include<stdlib.h>
#include<math.h>
#include"point.h"

/*Vedi file .h per delucidazioni sull'implementazione della struttura*/


struct point{

    float x;
    float y;

};


float ascissa(Point p){
    return p->x; //Operatore freccia perchè a è un puntatore. Per accedere ai campi di un puntatore a struttura è necessario l'operatore freccia
}

float ordinata(Point p){
    return p->y;
}

float distanza(Point p1, Point p2){
    float x1 = p1->x;
    float x2 = p2->x;

    float y1 = p1->y;
    float y2 = p2->y;

    float distanza = sqrt(pow((x2-x1), 2)+pow((y2-y1), 2));

    return distanza;
}

Point makepoint(float x, float y){
    
    Point a = malloc(sizeof(struct point)); //Necessario perchè point è un PUNTATORE alla struttura: il compilatore ha bisogno di conoscere la q.tà di memoria da allocare
    a->x = x;
    a->y = y;

    return a;
}

Point spostapunto(Point p, float x, float y){

    p->x = p->x + x;
    p->y = p->y + y;

    return p;

}

Point centroide(Point a[], int m){

    float x = 0.0, y = 0.0;

    for(int i = 0; i<m; i++){
        x += a[i]->x;
        y += a[i]->y;
    }

    x = x/m;
    y = y/m;    
    
    return makepoint(x, y);
}