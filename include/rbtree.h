#ifndef RBTREE_H
#define RBTREE_H

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


#endif
