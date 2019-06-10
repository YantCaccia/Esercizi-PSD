#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "list.h"

List in_list(Btree* tree, List list) {
    if(!getRight(*(tree)) && !getLeft(*(tree))) return list;

    if(getRight(*(tree)) || getLeft(*(tree))) addHead(list, getBtreeRoot(*(tree)));

    Btree left = getLeft(*tree);
    Btree right = getRight(*tree);
    in_list(&left, list);
    in_list(&right, list);
    return list;
}

int main(int argc, char* argv[]) {
    Btree h = newTree();

    int d = 10;
    int c = 5;
    int q = 4;
    int s = 7;
    int n = 9;

    Btree t1 = buildTree(NULL, NULL, &d);
    Btree t2 = buildTree(NULL, NULL, &c);
    Btree t3 = buildTree(t1, t2, &q);
    Btree t4 = buildTree(NULL, NULL, &s);
    Btree t5 = buildTree(t3, t4, &n);

    List nlist = newList();

    in_list(&(t5), nlist);

    printf("Albero: ");
    preOrder(t5);
    printf("\n");

    printList(nlist);
}