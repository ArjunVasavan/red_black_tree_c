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

 // replacement: for act as double black.
//  replacement_parent: for acting as double black parent if double black is an NULL

void fix_delete(node** root, node* replacement, node* replacement_parent) {

    while ( replacement != *root && ( replacement == NULL || replacement->colour == BLACK ) ) {

        if ( replacement == replacement_parent->left_pointer ) { // double black is on left side

            node* sibling = replacement_parent->right_pointer;

            // case 1
            if ( sibling != NULL && sibling->colour == RED ) {
                sibling->colour = BLACK;
                replacement_parent->colour = RED;
                left_rotate(root,replacement_parent);
                sibling = replacement_parent->right_pointer;
            }

        }
    
    }


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

// u: node to change.
// v: node we are putting on u's position.

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

void delete_node(node** root, int value ) {

    // finding node to delete

    node* curr =*root;
    while (curr != NULL) {
        if ( value < curr->data ) {
            curr = curr->left_pointer;
        } else if ( value > curr->data ) {
            curr = curr->right_pointer;
        } else { // founded the value
            break;
        }
    }

    if ( curr == NULL ) {
        printf("Data Not Found!\n");
        return;
    }

    // Saving Some data 
    node* node_to_delete = curr;
    node* replacement = NULL; // to check where is the double node can be NULL also
    node* replacement_parent = NULL; // parent of that double node ( needed when replacement is NULL)
    colour_t original_colour = curr->colour;

 // BST deletion there are three situations

    if ( curr->left_pointer == NULL ) {
        // situation 1: theres no left child for curr
        // this also handles no child on both side issue also

        replacement = curr->right_pointer;
        replacement_parent = curr->parent_pointer;
        transplant(root,curr,curr->right_pointer);

    } else if ( curr->right_pointer == NULL ) {
        // situation 2: theres no right child for curr

        replacement = curr->left_pointer;
        replacement_parent = curr->parent_pointer;
        transplant(root,curr,curr->left_pointer);

    } else {
        // situation 3: two childrens are present

        node* successor = find_min(curr->right_pointer);
        original_colour = successor->colour;
        replacement = successor->right_pointer;
        // successor has no left child as its the minimum but it may have an 
        // right child and that rght child is what which replaces successor

        if ( successor->parent_pointer == curr ) {
            // successor is direct right child of curr
            replacement_parent = successor;
        } else { // successor is deep inside
            // as successor is deep insdie first we are detatching it first
            replacement_parent = successor->parent_pointer;
            transplant(root,successor,successor->right_pointer);
            successor->right_pointer = curr->right_pointer;
            successor->right_pointer->parent_pointer = successor;

        }

        // putting successor to curr's position

        transplant(root,curr,successor);
        successor->left_pointer = curr->left_pointer;
        successor->left_pointer->parent_pointer = successor;
        successor->colour = curr->colour;

    }

    free(node_to_delete);

    if ( original_colour == BLACK ) {

        fix_delete(root,replacement,replacement_parent);
        
    }

}





