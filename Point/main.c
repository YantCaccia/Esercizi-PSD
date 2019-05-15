#include"point.h"
#include<stdio.h>
#include<stdlib.h>

void es_dis_min(Point arr[], int num_punti){
    
    int dis_min, m = 0;

    printf("Distanza minima:\n");
    scanf("%d", &dis_min);

    for(int i = 0;i<num_punti;i++)
        for(int j = i+1;j<num_punti;j++)
            if(distanza(arr[i], arr[j])<=dis_min)
                m++;

    printf("M: [%d]\n", m);

    return;
}

void es_dis_max(Point arr[], int num_punti){

    float max = 0.0;

    for(int i = 0;i<num_punti;i++)
        for(int j = i+1;j<num_punti;j++){
            float dis = distanza(arr[i], arr[j]);
            if(dis>=max)
                max=dis;
        }

    printf("Max: [%f]\n\n", max);

    return;

}

int main (void){

    int num_punti;

    printf("Quanti punti vuoi inserire?\n");
    scanf("%d", &num_punti);

    Point *arr = malloc(num_punti*sizeof(Point));

    for(int i = 0;i<num_punti;i++){
        
        float x, y;

        printf("\nPunto n.%d:\n", i+1);
        
        printf("Ascissa: ");
        scanf("%f", &x);

        printf("\nOrdinata: ");
        scanf("%f", &y);

        printf("\n");

        arr[i] = makepoint(x, y);
        
    }


    int codop;

    while(1){

    printf("Cosa vuoi fare?\n1.Distanza minima\n2.Distanza massima\n3.Centroide\n4.Sposta punto\n5.Esci\n");
    scanf("%d", &codop);
    getchar();
    printf("\n");

    switch (codop) {
        case 1: es_dis_min(arr, num_punti);
                break;
           
        case 2: es_dis_max(arr, num_punti);
                break;

        case 5: return 0;

        case 3: {
                Point centr = centroide(arr, num_punti);
                printf("X: [%.2f]\n", ascissa(centr));
                printf("Y: [%.2f]\n", ordinata(centr));
                break;
            }
        case 4: {
                int i;
                float x, y;
                printf("Quale punto vuoi spostare?\n");
                scanf("%d", &i);
                printf("Di quanto vuoi spostare l'ascissa?\n");
                scanf("%f", &x);
                printf("Di quanto vuoi spostare l'ordinata?\n");
                scanf("%f", &y);
                spostapunto(arr[--i], x, y);
                printf("Nuova X: [%.2f]\nNuova Y:[%.2f]\n", ascissa(arr[i]), ordinata(arr[i]));

            }
        }


    }
        


    return 0;
}