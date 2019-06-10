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
void inOrder(Btree tree);
void visitByLevels(Btree tree);
void visitByLevelsBrutta(Btree sons[], int dim);
int numberOfNodes(Btree tree);
int heightOfTree(Btree tree);
Item search(Btree tree, Item item);
Item min(Btree tree);
Item max(Btree tree);
void insert(Btree *tree, Item item);
void delete(Btree *tree, Item item);
void balanced(Btree *tree, Item *arr, int inizio, int fine);
int areEquals(Btree a, Btree b);
void fromString(Btree *b, Item it);