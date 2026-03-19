#include "include/rbtree.h"
#include <stdio.h>

int main(int argc, char** argv) {

    node* root = NULL;

    int n;

    printf("Enter 5 Elements: ");
    for ( int i = 0 ; i < 5 ; i++ ) {

        scanf("%d",&n);
        root = bst_insert(root,n);

    }

    printf("Enter what to search: ");
    scanf("%d",&n);
    search(&root,n);
    find_min(root);
    find_max(root);

}
