#include "../include/rbtree.h"
#include <cstddef>
#include <stdio.h>

void inorder(node* root) {

    if ( root == NULL ) {
        return;
    }

    inorder(root->left_pointer);

    printf("%d ",root->data);

    inorder(root->right_pointer);

}

void print_tree_lines(node* root, char* prefix, int is_left) {
    if (root == NULL) return;

    printf("%s", prefix);
    printf("%s", is_left ? "|-- " : "`-- ");
    printf("%d\n", root->data);

    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix,
             is_left ? "|   " : "    ");

    print_tree_lines(root->left_pointer,  new_prefix, 1);
    print_tree_lines(root->right_pointer, new_prefix, 0);
}
