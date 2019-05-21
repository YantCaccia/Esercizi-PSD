#include <stdio.h>
#include "btree.h"
#include "item.h"

int main(void) {
    Item it1 = "d";
    Btree d = buildTree(NULL, NULL, it1);

    Item it2 = "o";
    Btree o = buildTree(NULL, NULL, it2);

    Item it3 = "q";
    Btree q = buildTree(NULL, NULL, it3);

    Item it4 = "p";
    Btree p = buildTree(NULL, NULL, it4);

    Item it5 = "s";
    Btree s = buildTree(NULL, NULL, it5);

    Item it6 = "l";
    Btree l = buildTree(o, q, it6);

    Item it7 = "c";
    Btree c = buildTree(p, s, it7);

    Item it8 = "a";
    Btree a = buildTree(d, l, it8);

    Item it9 = "h";
    Btree h = buildTree(a, c, it9);

    preOrder(h);
    printf("\n");

    postOrder(h);
    printf("\n");

    simm(h);
    printf("\n");
}