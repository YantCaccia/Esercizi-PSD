#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

int main(void) {
    int codop;
    List list = newList();
    List clone = newList();

    while(1) {
        printf(
            "\nCosa vuoi fare?\n1.Inserisci elemento in testa\n2.Rimuovi elemento in testa\n3.Stampa elemento in "
            "testa\n4.Inserisci elemento in coda\n5.Inserisci elemento (specifica la posizione)\n6.Ordina "
            "lista\n7.Reverse\n8.Controlla se e' vuota\n9.Clona lista\n10.Stampa lista\n11.Stampa clone\n12.Cerca "
            "elemento\n99.Esci\n");
        scanf(" %d", &codop);
        printf("\n");

        switch(codop) {
            case 1: {
                printf("Che elemento vuoi inserire?\n");
                Item item = in_item();
                addHead(list, item);
                break;
            }
            case 2:
                free(removeHead(list));
                break;

            case 8:
                printf("%s\n", isEmpty(list) ? "Vuota" : "Non vuota");
                break;

            case 3:
                out_item(getFirst(list));
                printf("\n");
                break;

            case 10:
                printList(list);
                printf("\n");
                break;

            case 6:
                sortList(list);
                break;

            case 4: {
                printf("Che elemento vuoi inserire?\n");
                Item item = in_item();
                insertTail(list, item);
                break;
            }

            case 5: {
                printf("Che elemento vuoi inserire?\n");
                Item item = in_item();
                int pos;
                printf("Dove lo vuoi inserire?\n");
                scanf(" %d", &pos);
                insertItem(list, item, pos);
                break;
            }

            case 7:
                reverseList(list);
                break;

            case 9:
                clone = cloneList(list);
                break;

            case 11:
                printList(clone);
                break;

            case 12: {
                printf("Cosa vuoi cercare?\n");
                Item item = in_item();
                printf("[%d]\n", searchItem(list, item));
                break;
            }

            case 13: {
                int pos;
                printf("Posizione dell'elemento da eliminare:\n");
                scanf(" %d", &pos);
                removeItemPos(list, pos);
                break;
            }

            case 14: {
                printf("Elemento da eliminare:\n");
                Item elem = in_item();
                removeItemElem(list, elem);
                break;
            }

            case 99:
                printf("\nCiao!\n");
                return 1;
        }
    }

    return 1;
}