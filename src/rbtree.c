#include "../include/rbtree.h"

node* create_node(int value) {

    node* new_node = malloc(sizeof(node));

    if ( new_node == NULL ) {
        printf("[create_node]: Error creating node\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->colour = RED;
    new_node->left_pointer = NULL;
    new_node->parent_pointer = NULL;
    new_node->right_pointer = NULL;

    return new_node;
}

void insert(node **root, int value) {

    node* new_node = create_node(value);

    if ( *root == NULL ) {
        new_node->colour = BLACK;
        *root = new_node;
        return;
    }

    node* par = NULL;
    node* curr= *root;

    while ( curr != NULL ) {
        par = curr;

        if ( value < curr->data ) {
            curr = curr->left_pointer;
        } else if ( value > curr->data ) {
            curr = curr->right_pointer;
        }
    }

    new_node->parent_pointer = par;

    if ( value < par->data ) {
        par->left_pointer = new_node;
    } else {
        par->right_pointer = new_node;
    }
}
