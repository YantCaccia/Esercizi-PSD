#include "btree.h"
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