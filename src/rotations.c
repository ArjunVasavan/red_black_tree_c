#include "../include/rbtree.h"

void left_rotate(node** root, node* node_x) {

    node* node_y = node_x->right_pointer;

    node_x->right_pointer = node_y->left_pointer;

    if ( node_y->left_pointer != NULL ) {
        node_y->left_pointer->parent_pointer = node_x;
    }

    // This is when x is root
    if ( node_x->parent_pointer == NULL ) {
        *root = node_y;
        node_y->parent_pointer = NULL;
    } else { // This is when x has an parent

        node_y->parent_pointer = node_x->parent_pointer;
        if ( node_x == node_x->parent_pointer->left_pointer ) {
            node_x->parent_pointer->left_pointer = node_y;
        } else {
            node_x->parent_pointer->right_pointer = node_y;
        }
    }
    node_x->parent_pointer = node_y;
    node_y->left_pointer = node_x;
}

