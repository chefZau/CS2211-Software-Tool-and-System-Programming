#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include "datatype.h"


BStree bstree_ini(void){
    BStree bst = (BStree)malloc(sizeof(BStree));
    *bst = NULL;
    return bst;
}


BStree_node* new_node(Key key, Data data){
    BStree_node* new = (BStree_node*) malloc(sizeof(BStree_node));
    new->data = data;
    new->key = key;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void bstree_recursive_insert(BStree_node** current, Key key, Data data){

    if ( *current == NULL ) {
        BStree_node* new = new_node(key, data);
        *current = new;
    }else {
        if ( key_comp(key, (*current)->key) < 0 ){
            bstree_recursive_insert(&((*current)->left), key, data);
        }else if ( key_comp(key,(*current)->key) > 0 )
            bstree_recursive_insert(&((*current)->right), key, data);
        else
            ;
    }
}

void bstree_insert(BStree bst, Key key, Data data){
    bstree_recursive_insert(bst,key,data);
}


Data bstree_recursive_search(BStree_node* current, Key key){
    if ( current == NULL ) {
        return NULL;
    }else {
        if ( key_comp(key, current->key) < 0 )
            return bstree_recursive_search(current->left, key);
        else if ( key_comp(key, current->key) > 0 )
            return bstree_recursive_search(current->right, key);
        else {
            return current->data;
        }
    }
}


Data bstree_search(BStree bst, Key key){

    return bstree_recursive_search(*bst, key);
}


void bstree_recursive_traversal(BStree_node* current){
    if(current!=NULL){
        bstree_recursive_traversal(current->left);

        key_print(current->key);
        data_print(current->data);
        printf("\n");

        bstree_recursive_traversal(current->right);
    }
}

void bstree_traversal(BStree bst){
    bstree_recursive_traversal(*bst);
}

void bstree_recursive_free(BStree_node * current){
    if(current!=NULL){
        bstree_recursive_free(current->left);
        bstree_recursive_free(current->right);

        key_free(current->key);
        data_free(current->data);
        free(current);
    }
}

void bstree_free(BStree bst){
    bstree_recursive_free(*bst);
    free(bst);
}
