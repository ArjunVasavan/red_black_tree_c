#include "../include/rbtree.h"

void fix_insert(node** root, node* new_node ) {

    while ( new_node != *root && new_node->parent_pointer->colour == RED ) {

        node* parent_node = new_node->parent_pointer;
        node* grand_node =  parent_node->parent_pointer;

        if ( parent_node == grand_node->left_pointer ) { // bented to left side

            node* uncle_node = grand_node->right_pointer;

            if ( uncle_node != NULL && uncle_node->colour == RED ) {

                parent_node->colour = BLACK;
                grand_node->colour = RED;
                uncle_node->colour = BLACK;

                new_node = grand_node;

            } else {

                if ( new_node == parent_node->right_pointer ) { // now its on LR fashion

                    left_rotate(root,parent_node);


                    new_node = parent_node;
                    parent_node = new_node->parent_pointer;

                }
                // case for RR or left over of LRs R rotation

                grand_node->colour = RED;
                parent_node->colour = BLACK;

                right_rotate(root,grand_node);
            }
        } else { // bented to right side

            node* uncle_node = grand_node->left_pointer;

            if ( uncle_node != NULL && uncle_node->colour == RED ) {

                parent_node->colour = BLACK;
                uncle_node->colour = BLACK;
                grand_node->colour = RED;

                new_node = grand_node;

            } else {

                if ( new_node == parent_node->left_pointer ) { // RL case

                    right_rotate(root,parent_node);
                    new_node = parent_node;
                    parent_node = new_node->parent_pointer;

                }

                grand_node->colour = RED;
                parent_node->colour = BLACK;

                left_rotate(root,grand_node);
            }
        }
    }

    (*root)->colour = BLACK;
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

    fix_insert(root,new_node);
}


