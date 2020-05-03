//
// Created by MingCong Zhou on 11/27/2018.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datatype.h"

char * string_dup(char *str){
    char *copy = malloc((1 + strlen(str)) * sizeof(char));
    if(copy == NULL){
        fprintf(stderr,
                "Error in string_dup - unable to allocate required memory\n");
        exit(EXIT_FAILURE);
    }else{
        strcpy(copy,str);
    }
    return copy;
}

Key key_gen(char *skey1, char *skey2){
    Key key = (Key) malloc(sizeof(Key_struct));
    if(key == NULL){
        fprintf(stderr,
                "Error in key_gen - unable to allocate required memory\n");
        exit(EXIT_FAILURE);
    }else{
        key->skey1 = string_dup(skey1);
        key->skey2 = string_dup(skey2);
    }
    return key;
}

int key_comp(Key key1, Key key2){

    int first_comparison = strcmp(key1->skey1,key2->skey1);
    if(first_comparison != 0){
        return first_comparison;
    }else{
        return strcmp(key1->skey2,key2->skey2);
    }
}

void key_print(Key key){
    printf("%s  %s  ",key->skey1,key->skey2);
}

void key_free(Key key){
    free(key->skey1);
    free(key->skey2);
    free(key);
}

Data data_gen(int idata){
    Data data = (Data) malloc(sizeof(int));
    data_set(data,idata);
    return data;
}

void data_set(Data data, int idata){
    *data = idata;
}

void data_print(Data data){
    printf("%d",*data);
}


void data_free(Data data){
    free(data);
}



