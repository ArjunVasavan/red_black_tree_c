#include "../include/rbtree.h"
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

void search(node** root, int value ) {

    node* curr = *root;

    while (curr != NULL ) {
    
        if ( value > curr->data ) {
            curr = curr->right_pointer;
        } else if ( value < curr->data ) {
            curr = curr->left_pointer;
        } else if ( value == curr->data ) {
            printf("founded\n");
            return;
        }

    }
    return;
}

void find_min(node *root) {

    if ( root == NULL ) {
        printf("Tree is Empty");
        return;
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
        return;
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
        root->left_pointer = bst_insert(root->left_pointer,value);
    } 

    return root;
}

void transplant(node** root, node* u, node* v) {

    if ( u ->parent_pointer == NULL ) { // u is root

        *root = v; // now v is root

    } else if ( u == u->parent_pointer->left_pointer ) { // u is left child

        u->parent_pointer->left_pointer = v;

    } else {
        u->parent_pointer->right_pointer = v;
    }

    if ( v != NULL ) {
        v->parent_pointer = u->parent_pointer;
    }

}



