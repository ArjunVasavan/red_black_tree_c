#ifndef RBTREE_H
#define RBTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    RED,
    BLACK
}colour_t;

typedef struct node {

    int data;
    struct node* left_pointer;
    struct node* right_pointer;
    struct node* parent_pointer;
    colour_t colour;
}node;

void insert(node** root,int value);
void search(node** root,int value);
void find_min(node* root);
void find_max(node* root);

// TESTING ////////////////////////////
/* This is for testing bst */

node* bst_insert(node* root, int value );
void inorder(node* root);
void print_tree_lines(node* root, char* prefix, int is_left);
void left_rotate(node** root, node* node_x);

#endif
