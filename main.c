#include "include/rbtree.h"

int main(int argc, char** argv) {

    node* root = NULL;

    int n;

    for ( int i = 0 ; i < 5 ; i++ ) {

        scanf("%d",&n);
        bst_insert(root,n);

    }

    search(&root,8);
    find_min(root);
    find_max(root);

}
