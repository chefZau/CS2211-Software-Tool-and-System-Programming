/**
 * This program deal with the data in the
 * binary search tree.
 * @author MingCong,ZHOU
 * @studentNumber: 250945414
 * @studentAccount: mzhou272
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"

/**
 * Dynamically allocate memory to hold a Key,
 * set Key’s id to be in_id. Dynamically allocate memory for the Key’s name
 * so that name will contain what is in ’in_name’.
 * @param in_name a string ends with ’\0’
 * @param in_id an integer
 * @return a pointer of type pointer to Key,
 *         pointing to an allocated memory containing a Key
 */
Key *key_construct(char *in_name, int in_id) {

    Key *newKey = (Key *) malloc(sizeof(Key));
    newKey->name = strdup(in_name);
    newKey->id = in_id;

    return newKey;
}

/**
 *  This method would compare the two keys that are entered.
 *  This method has two possibilities
 *  when name key1 and key2 is the same and when they are not the same
 *  if they are the same on name, compare the id.
 *
 * @param key1  one of the Keys
 * @param key2  one of the Keys
 * @return   when key1 < key2, return value -1
 *           when key1 = key2, return value 0
 *           when key1 > key2, return value 1
 */
int key_comp(Key key1, Key key2) {

    //Strcmp would return 1 0 -1 when the first argument
    // is bigger equal and larger
    int compare = strcmp(key1.name, key2.name);

    if (compare == 0) {                 //share the same name, then compare id

        if (key1.id > key2.id) return 1;
        else if (key1.id < key2.id) return -1;
        else return 0;

    } else {                 //when they are not the same, compare the name

        return strcmp(key1.name, key2.name);
    }
}

/**
 *  ( key->name key->id ) is printed
 * @param key  ’key’: a pointer to Key
 */
void print_key(Key *key) {
    printf("（ %-8s  %8d ）", key->name, key->id);
}

/**
 * node.key is printed and then the node.data is printed
 * @param node   a node
 */
void print_node(Node node) {
    print_key(node.key);
    printf("%d\n", node.data);
}

