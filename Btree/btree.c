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

void simm(Btree tree) {
    if(!tree) return;

    simm(tree->left);
    out_item(tree->value);
    simm(tree->right);
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