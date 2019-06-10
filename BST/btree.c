#include "btree.h"
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct btree {
    Item value;
    struct btree *left;
    struct btree *right;
};

Btree newTree() {
    return NULL;
}

int isEmptyTree(Btree tree) {
    return tree == NULL ? 1 : 0;
}

Btree buildTree(Btree left, Btree right, Item item) {
    Btree tree = malloc(sizeof(struct btree));
    tree->left = left;
    tree->right = right;
    tree->value = item;

    return tree;
}

Item getBtreeRoot(Btree tree) {
    return !isEmptyTree(tree) ? tree->value : NULL;
}

Btree getRight(Btree tree) {
    return !isEmptyTree(tree) ? tree->right : NULL;
}

Btree getLeft(Btree tree) {
    return !isEmptyTree(tree) ? tree->left : NULL;
}

void preOrder(Btree tree) {
    if(!tree) return;

    out_item(tree->value);
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(Btree tree) {
    if(!tree->left) {
        out_item(tree->value);
        return;
    }

    postOrder(tree->left);
    postOrder(tree->right);
    out_item(tree->value);
}

void inOrder(Btree tree) {
    if(!tree) return;

    inOrder(tree->left);
    out_item(tree->value);
    inOrder(tree->right);
}

void visitByLevels(Btree tree) {
    Btree treeArray[1];
    treeArray[0] = tree;
    visitByLevelsBrutta(treeArray, 1);
}

void visitByLevelsBrutta(Btree sons[], int dim) {
    if(sons[0] == NULL) return;

    Btree *nsons = malloc(sizeof(struct btree) * 1);
    nsons[0] = NULL;
    int ndim = 0;

    for(int i = 0; i < dim; i++) {
        out_item(sons[i]->value);
    }
    printf("\n");

    for(int i = 0, j = 0; i < dim; i++) {
        Btree left = sons[i]->left;
        Btree right = sons[i]->right;

        if(left) {
            nsons = realloc(nsons, sizeof(struct btree) * ++ndim);
            nsons[j++] = left;
        }
        if(right) {
            nsons = realloc(nsons, sizeof(struct btree) * ++ndim);
            nsons[j++] = right;
        }
    }

    visitByLevelsBrutta(nsons, ndim);
}

int numberOfNodes(Btree tree) {
    if(isEmptyTree(tree))
        return 0;
    else if(isEmptyTree(tree->left) && isEmptyTree(tree->right))
        return 1;
    else
        return 1 + numberOfNodes(tree->left) + numberOfNodes(tree->right);
}

int heightOfTree(Btree tree) {
    if(isEmptyTree(tree->left) && isEmptyTree(tree->right)) return 0;
    int left = heightOfTree(tree->left);
    int right = heightOfTree(tree->right);

    if(left > right)
        return 1 + left;
    else
        return 1 + right;
}

void insert(Btree *tree, Item item) {
    if(isEmptyTree(*tree)) {
        *tree = malloc(sizeof(struct btree));
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->value = item;
    }

    if(!comp_items(item, (*tree)->value)) return;
    if(comp_items(item, (*tree)->value) > 0) return insert(&(*tree)->right, item);
    if(comp_items(item, (*tree)->value) < 0) return insert(&(*tree)->left, item);
}

void balanced(Btree *tree, Item *arr, int inizio, int fine) {
    /*
     * PROBABILMENTE crea un albero bilanciato a partire da un array ordinato
     */

    if(fine <= inizio) return;

    int n = (fine - inizio) / 2;
    Item v = arr[n];

    if(isEmptyTree(*tree)) {
        *tree = malloc(sizeof(struct btree));
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->value = v;
    }

    balanced(&(*tree)->left, arr, inizio, n);
    balanced(&(*tree)->right, arr + n + 1, 0, n - n / 2);
}

Item search(Btree tree, Item item) {
    if(isEmptyTree(tree)) return NULL;
    if(!comp_items(item, tree->value)) return (tree->value);
    if(comp_items(item, tree->value) > 0) search(tree->right, item);
    if(comp_items(item, tree->value) < 0) search(tree->left, item);
}

Item min(Btree tree) {
    if(isEmptyTree(tree)) return NULL;
    if(!tree->left) return tree->value;
    return min(tree->left);
}

Item max(Btree tree) {
    if(isEmptyTree(tree)) return NULL;
    if(!tree->right) return tree->value;
    return max(tree->right);
}

void delete(Btree *tree, Item item) {
    if((*tree) == NULL) return;

    if(comp_items(item, (*tree)->value) > 0) delete(&(*tree)->right, item);
    if(comp_items(item, (*tree)->value) < 0) delete(&(*tree)->left, item);
    if(!comp_items(item, (*tree)->value)) {
        /*Caso 1: il nodo ha al massimo un figlio*/
        if(!(*tree)->left && !(*tree)->right)
            (*tree) = NULL;
        else if((*tree)->left && !(*tree)->right)
            (*tree) = (*tree)->left;
        else if(!(*tree)->left && (*tree)->right)
            (*tree) = (*tree)->right;
        /*-----------------------------------------*/

        /*Caso 2: il nodo ha due figli*/
        else if((*tree)->left && (*tree)->right) {
            (*tree)->value = max((*tree)->left);
            delete(&(*tree)->left, max((*tree)->left));
        }
        /*----------------------------*/
    }
}

int areEquals(Btree a, Btree b) {
    /*Check if Btree a is equal to Btree b*/

    if(!a && !b) return 1;

    if(comp_items(a->value, b->value)) return 0;  // ritorna 0 se i due valori non sono uguali

    return (areEquals(a->left, b->left) && (areEquals(a->right, b->right)));
}