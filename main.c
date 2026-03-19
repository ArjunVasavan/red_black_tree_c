#include "include/rbtree.h"
#include <stdio.h>

int main(int argc, char** argv) {

    node* root = NULL;

    int n;

    printf("Enter 5 Elements: ");
    for ( int i = 0 ; i < 3 ; i++ ) {

        scanf("%d",&n);
        root = bst_insert(root,n);

    }

    // printf("Enter what to search: ");
    // scanf("%d",&n);
    

    // print the tree
    printf("%d\n", root->data);                    // print root first
    print_tree_lines(root->left_pointer,  "", 1);  // left subtree
    print_tree_lines(root->right_pointer, "", 0);  // right subtree

}
