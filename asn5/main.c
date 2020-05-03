#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "bstree.h"
#include "matrix.h"
void bstree_test();
void matrix_test();


int main() {
    matrix_test();

    return 0;
}

void matrix_test(){

    /*Test 1*/
    /*
     * out put should be:
     * a  a  5
       a  b  5
       b  b  4
       c  c  6
       d  d  0
       e  e  2
       f  a  3
       f  f  3
       z  z  1
     */
    printf("Test 1\n");
    Matrix m = matrix_construction();
    matrix_set(m,"d","d",0);
    matrix_set(m,"z","z",1);
    matrix_set(m,"e","e",2);
    matrix_set(m,"f","f",3);
    matrix_set(m,"f","a",4);
    matrix_set(m,"b","b",5);
    matrix_set(m,"a","a",6);
    matrix_set(m,"c","c",7);
    matrix_set(m,"a","b",8);
    matrix_list(m);




    /*Test 2*/
    //Out put should be 876543210
    printf("Test 2\n");
    printf("%d",*matrix_get(m,"a","b"));
    printf("%d",*matrix_get(m,"c","c"));
    printf("%d",*matrix_get(m,"a","a"));
    printf("%d",*matrix_get(m,"b","b"));
    printf("%d",*matrix_get(m,"f","a"));
    printf("%d",*matrix_get(m,"f","f"));
    printf("%d",*matrix_get(m,"e","e"));
    printf("%d",*matrix_get(m,"z","z"));
    printf("%d",*matrix_get(m,"d","d"));
    printf("\n\n");

    /* Test 3*/
    //Output should be 76543210-1
    printf("test 3\n");
    matrix_set(m,"d","d",-1);
    matrix_set(m,"z","z",0);
    matrix_set(m,"e","e",1);
    matrix_set(m,"f","f",2);
    matrix_set(m,"f","a",3);
    matrix_set(m,"b","b",4);
    matrix_set(m,"a","a",5);
    matrix_set(m,"c","c",6);
    matrix_set(m,"a","b",7);
    printf("%d",*matrix_get(m,"a","b"));
    printf("%d",*matrix_get(m,"c","c"));
    printf("%d",*matrix_get(m,"a","a"));
    printf("%d",*matrix_get(m,"b","b"));
    printf("%d",*matrix_get(m,"f","a"));
    printf("%d",*matrix_get(m,"f","f"));
    printf("%d",*matrix_get(m,"e","e"));
    printf("%d",*matrix_get(m,"z","z"));
    printf("%d",*matrix_get(m,"d","d"));
    printf("\n\n");

    /* Test 4 */
    //output should be 876543210
    printf("Test 4\n");
    matrix_inc(m,"d","d",-1);
    matrix_inc(m,"z","z",0);
    matrix_inc(m,"e","e",1);
    matrix_inc(m,"f","f",2);
    matrix_inc(m,"f","a",3);
    matrix_inc(m,"b","b",4);
    matrix_inc(m,"a","a",5);
    matrix_inc(m,"c","c",6);
    matrix_inc(m,"a","b",7);
    printf("%d",*matrix_get(m,"a","b"));
    printf("%d",*matrix_get(m,"c","c"));
    printf("%d",*matrix_get(m,"a","a"));
    printf("%d",*matrix_get(m,"b","b"));
    printf("%d",*matrix_get(m,"f","a"));
    printf("%d",*matrix_get(m,"f","f"));
    printf("%d",*matrix_get(m,"e","e"));
    printf("%d",*matrix_get(m,"z","z"));
    printf("%d",*matrix_get(m,"d","d"));

    matrix_destruction(m);
}

void bstree_test(){
    printf("Hello, World!\n");
    BStree bst = bstree_ini();

    //Testing Insertion
    /*
     * out put should be:
     * a  a  5
       a  b  5
       b  b  4
       c  c  6
       d  d  0
       e  e  2
       f  a  3
       f  f  3
       z  z  1
     */
    bstree_insert(bst,key_gen("d","d"),data_gen(0));
    bstree_insert(bst,key_gen("z","z"),data_gen(1));
    bstree_insert(bst,key_gen("e","e"),data_gen(2));
    bstree_insert(bst,key_gen("f","f"),data_gen(3));
    bstree_insert(bst,key_gen("f","a"),data_gen(4));
    bstree_insert(bst,key_gen("b","b"),data_gen(5));
    bstree_insert(bst,key_gen("a","a"),data_gen(6));
    bstree_insert(bst,key_gen("c","c"),data_gen(7));
    bstree_insert(bst,key_gen("a","b"),data_gen(8));
    bstree_traversal(bst);

    /* Testing Search */
    // Result should be 012345678
    printf("%d",*bstree_search(bst,key_gen("d","d")));
    printf("%d",*bstree_search(bst,key_gen("z","z")));
    printf("%d",*bstree_search(bst,key_gen("e","e")));
    printf("%d",*bstree_search(bst,key_gen("f","f")));
    printf("%d",*bstree_search(bst,key_gen("f","a")));
    printf("%d",*bstree_search(bst,key_gen("b","b")));
    printf("%d",*bstree_search(bst,key_gen("a","a")));
    printf("%d",*bstree_search(bst,key_gen("c","c")));
    printf("%d",*bstree_search(bst,key_gen("a","b")));

    /*Testing Search Again*/
    //Result should be 876543210
    printf("\n\n");
    printf("%d",*bstree_search(bst,key_gen("a","b")));
    printf("%d",*bstree_search(bst,key_gen("c","c")));
    printf("%d",*bstree_search(bst,key_gen("a","a")));
    printf("%d",*bstree_search(bst,key_gen("b","b")));
    printf("%d",*bstree_search(bst,key_gen("f","a")));
    printf("%d",*bstree_search(bst,key_gen("f","f")));
    printf("%d",*bstree_search(bst,key_gen("e","e")));
    printf("%d",*bstree_search(bst,key_gen("z","z")));
    printf("%d",*bstree_search(bst,key_gen("d","d")));


    free(bst);

}