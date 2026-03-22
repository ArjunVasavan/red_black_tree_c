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

void search(node** root, int value ) {

    node* curr = *root;

    while (curr != NULL ) {

        if ( value > curr->data ) {
            curr = curr->right_pointer;
        } else if ( value < curr->data ) {
            curr = curr->left_pointer;
        } else if ( value == curr->data ) {
            printf("Value %d found in tree\n",value);
            return;
        }

    }

    printf("Value %d not found!\n",value);
    return;
}

node* find_min(node *root) {

    if ( root == NULL ) {
        printf("Tree is Empty");
        return NULL;
    }

    node* curr = root;

    while ( curr->left_pointer != NULL ) {
        curr = curr->left_pointer;
    }

    return curr;
}

node* find_max(node *root) {

    if ( root == NULL ) {
        printf("Tree is Empty");
        return NULL;
    }

    node* curr = root;

    while ( curr->right_pointer != NULL ) {
        curr = curr->right_pointer;
    }

    return curr;
}

void find_min_wrapper(node* root) {
    if ( root == NULL ) {
        printf("Tree is Empty\n");
        return;
    }
    node* result;
    result = find_min(root);
    printf("Minimum value in the tree is %d\n",result->data);

}
void find_max_wrapper(node* root) {
    if ( root == NULL ) {
        printf("Tree is Empty\n");
        return;
    }
    node* result;
    result = find_max(root);
    printf("Maximum value in the tree is %d\n",result->data);
}
void delete_min(node** root) {
    if ( *root == NULL ) {
        printf("Tree is Empty\n");
        return;
    }

    node* min = find_min(*root);
    delete_node(root,min->data);
}
void delete_max(node** root) {
    if ( *root == NULL ) {
        printf("Tree is Empty\n");
        return;
    }

    node* max = find_max(*root);
    delete_node(root,max->data);
}
