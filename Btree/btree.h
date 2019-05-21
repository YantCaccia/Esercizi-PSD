#include "item.h"

typedef struct btree *Btree;

Btree newTree();
int isEmptyTree(Btree tree);
Btree buildTree(Btree left, Btree right, Item item);
Item getBtreeRoot(Btree tree);
Btree getRight(Btree tree);
Btree getLeft(Btree tree);
void preOrder(Btree tree);
void postOrder(Btree tree);
void simm(Btree tree);