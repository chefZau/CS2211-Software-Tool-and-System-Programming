/**
 * This is a program for creating binary search tree
 * @author MingCong,ZHOU
 * @studentNumber: 250945414
 * @studentAccount: mzhou272
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/**
 * dynamically allocate memory for TreeNode, Tree position array
 * @param size size of an array that the user who want to create
 * @return a pointer of type BStree,
 */
BStree bstree_ini(int size) {


    //dynamically allocate memory of type BStree_struct
    BStree newTree = (BStree) malloc(sizeof(BStree_struct));

    //allocate memory for a Node array of size+1 for member tree_nodes
    newTree->tree_nodes = (Node *) malloc((size + 1) * sizeof(Node));

    //allocate memory for an unsigned char array of size+1 for member is_free
    newTree->is_free = (unsigned char *) malloc((size + 1) * sizeof(unsigned char));

    // set all entries of is_free to 1
    for (int i = 0; i < size; i++) {
        newTree->is_free[i] = 1;
    }

    // set member size to ’size’
    newTree->size = size;

    return newTree;
}

/**
 * Create a Tree Node
 * @param key  a pointer to Key
 * @param data  an integer
 * @return  the new node
 */
Node createNode(Key *key, int data) {

    Node newTreeNode = {key, data};
    return newTreeNode;
}

/**
 *  ’data’ with ’key’ is inserted into ’bst’
 *  if ’key’ is already in ’bst’, do nothing
 * @param bst  a binary search tree
 * @param key  a pointer to Key
 * @param data  an integer
 * @param index  the index of the arrayTree
 */
void helperInsert(BStree bst, Key *key, int data, int index) {

    if (index <= bst->size) {  // check array bound

        if (bst->is_free[index] == 1) {  //null nothing in this
            bst->tree_nodes[index] = createNode(key, data);
            bst->is_free[index] = 0;
            return;

        } else {  //is_free[i] == 0
            int comparison = key_comp(*bst->tree_nodes[index].key, *key);
            if (comparison > 0) {                   //greater than the invader, call left
                return helperInsert(bst, key, data, 2 * index);
            } else if (comparison < 0) {            //smaller than the invader, call right
                return helperInsert(bst, key, data, (2 * index) + 1);
            }
        }
    } else {
        printf("The array is out of bound");
        return;
    }
}

void bstree_insert(BStree bst, Key *key, int data) {
    //call the recursive function, start at index 1
    helperInsert(bst, key, data, 1);
}


/**
 * print all the nodes in bst using inOrder traversal
 * @param bst a binary search tree
 * @param index is the index of the arrayTree
 */
void inOrderTraversal(BStree bst, int index) {
    if (index <= bst->size) {           //check array bound

        if (bst->is_free[index] == 1) {    //if there is nothing in it return
            return;                         //same as isLeaf or isempty
        } else {

            //visit left child and itself then right child
            inOrderTraversal(bst, 2 * index);
            print_node(bst->tree_nodes[index]);
            inOrderTraversal(bst, index * 2 + 1);
        }

    } else {
        printf("The array is out of bound");
        return;
    }
}

void bstree_traversal(BStree bst) {
    //call the recursive function, start at index 1
    return inOrderTraversal(bst, 1);
}

/**
 * Effect: all memory used by bst are freed
 * @param bst a binary search tree
 */
void bstree_free(BStree bst) {
    free(bst->is_free);
    free(bst->tree_nodes);
    free(bst);
}