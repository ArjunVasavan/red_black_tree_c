#include "../include/rbtree.h"
#include <stdio.h>
#include <time.h>

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

    printf("[insert]: (%d,%d)\n",new_node->data,new_node->colour);
}

void search(node** root, int value ) {

    node* curr = *root;

    while (curr != NULL ) {
    
        if ( value > curr->data ) {
            curr = curr->right_pointer;
        } else if ( value < curr->data ) {
            curr = curr->left_pointer;
        } else if ( value == curr->data ) {
            printf("founded\n");
        }

    }
    return;
}

void find_min(node *root) {

    if ( root == NULL ) {
        printf("Tree is Empty");
    }

    node* curr = root;

    while ( curr->left_pointer != NULL ) {
        curr = curr->left_pointer;
    }

    printf(" Minimum is %d\n",curr->data);
}

void find_max(node *root) {

    if ( root == NULL ) {
        printf("Tree is Empty");
    }

    node* curr = root;

    while ( curr->right_pointer != NULL ) {
        curr = curr->right_pointer;
    }

    printf(" Maximum is %d\n",curr->data);
}

node* bst_insert(node* root, int value ) {

    if ( root == NULL ) {
        
        node* new_node = create_node(value);
        return new_node;

    }

    if ( value > root->data ) {
        root->right_pointer = bst_insert(root->right_pointer,value);
    } else if ( value < root->data ) {
        root->left_pointer = bst_insert(root,value);
    } 

    return NULL;
}

