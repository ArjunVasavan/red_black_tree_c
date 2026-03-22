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
node* find_min(node* root);
node* find_max(node* root);
void delete_node(node** root, int value );
node* create_node(int value);

void left_rotate(node** root, node* node_x);
void right_rotate(node** root, node* node_x);

void print_menu();
void find_min_wrapper(node* root);
void find_max_wrapper(node* root);
void delete_min(node** root);
void delete_max(node** root);
void print_tree(node* root);

void inorder(node* root);
#endif
