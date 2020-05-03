//
// Created by MingCong Zhou on 11/27/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "bstree.h"
#include "matrix.h"

Matrix matrix_construction(void){
    Matrix new_matrix = bstree_ini();
}

unsigned char matrix_isin(Matrix m, Index index1, Index index2){
    Data search = bstree_search(m,key_gen(index1,index2));
    return (search!=NULL)?1:0;
}

Value *matrix_get(Matrix m, Index index1, Index index2){
    return bstree_search(m,key_gen(index1,index2));
}

void matrix_set(Matrix m, Index index1, Index index2, Value value){
    Data search = bstree_search(m,key_gen(index1,index2));
    if(search == NULL){
        bstree_insert(m,key_gen(index1,index2),data_gen(value));
    }else{
        *search = value;
    }
}

void matrix_inc(Matrix m, Index index1, Index index2, Value value){
    Data search = bstree_search(m,key_gen(index1,index2));
    if(search == NULL||*search != value){
        fprintf(stderr,
                "Error in key_gen - unable to allocate required memory\n");
    }else{
        (*search)++;
    }
}

void matrix_list(Matrix m){
    bstree_traversal(m);
}

void matrix_destruction(Matrix m){
    bstree_free(m);
}