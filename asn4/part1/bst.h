


#include "data.h"

typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;

typedef BStree_struct* BStree;   //创建一个对象叫BStree 他的type是 BStree_struct


BStree bstree_ini(int size);

void bstree_insert(BStree bst, Key *key, int data);
void helperInsert(BStree bst, Key *key, int data, int index);

void bstree_traversal(BStree bst);
void inOrderTraversal(BStree bst, int index);

void bstree_free(BStree bst);

