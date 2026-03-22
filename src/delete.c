#include "../include/rbtree.h"

// replacement: for act as double black.
//  replacement_parent: for acting as double black parent if double black is an NULL

void fix_delete(node** root, node* replacement, node* replacement_parent) {

    while ( replacement != *root && ( replacement == NULL || replacement->colour == BLACK ) ) {

        if ( replacement == replacement_parent->left_pointer ) { // double black is on left side

            node* sibling = replacement_parent->right_pointer;

            if ( sibling == NULL ) {

                // Sibling is NULL → equivalent to BLACK NIL node.
                // Cannot fix double-black locally (no sibling to rotate/recolor).
                // Move the double-black up to parent and continue fixing.
                replacement = replacement_parent;
                replacement_parent = replacement_parent->parent_pointer;
                continue;
            }

            // case 1
            if ( sibling != NULL && sibling->colour == RED ) {
                sibling->colour = BLACK;
                replacement_parent->colour = RED;
                left_rotate(root,replacement_parent);
                sibling = replacement_parent->right_pointer;
            }

            // case 2
            if (  ( sibling->left_pointer == NULL || sibling->left_pointer->colour == BLACK ) && 
                (sibling->right_pointer == NULL || sibling->right_pointer->colour == BLACK ) ) {


                sibling->colour = RED;

                replacement = replacement_parent;
                replacement_parent = replacement_parent->parent_pointer;

            } else {


                // case 3 
                // in case 3 near child colour will be red its colour is replaced

                if ( sibling->right_pointer == NULL || sibling->right_pointer->colour == BLACK ) {
                    sibling->left_pointer->colour = BLACK;
                    sibling->colour = RED;
                    right_rotate(root,sibling);
                    sibling = replacement_parent->right_pointer;
                } 

                // case 4

                sibling->colour = replacement_parent->colour;
                replacement_parent->colour = BLACK;
                sibling->right_pointer->colour = BLACK;
                left_rotate(root,replacement_parent);

                replacement = *root; // to close the loop

            }

        } else {  // double black is on right side

            node* sibling = replacement_parent->left_pointer;

            if ( sibling == NULL ) {

                // Sibling is NULL → equivalent to BLACK NIL node.
                // Cannot fix double-black locally (no sibling to rotate/recolor).
                // Move the double-black up to parent and continue fixing.
                replacement = replacement_parent;
                replacement_parent = replacement_parent->parent_pointer;
                continue;
            }

            // case 1

            if ( sibling != NULL && sibling->colour == RED ) {
                sibling->colour = BLACK;
                replacement_parent->colour = RED;
                right_rotate(root,replacement_parent);
                sibling = replacement_parent->left_pointer;
            }

            // case 2
            if ( ( sibling->left_pointer == NULL || sibling->left_pointer->colour == BLACK ) && 
                (sibling->right_pointer == NULL || sibling->right_pointer->colour == BLACK ) ) {

                sibling->colour = RED;

                replacement = replacement_parent;
                replacement_parent = replacement_parent->parent_pointer;

            } else {

                // case 3
                // in case 3 near child colour is replaced

                if ( sibling->left_pointer == NULL || sibling->left_pointer->colour == BLACK ) {

                    sibling->right_pointer->colour = BLACK;
                    sibling->colour = RED;
                    // rotated opposite to the side of Double black

                    left_rotate(root,sibling);

                    sibling = replacement_parent->left_pointer;

                }

                sibling->colour = replacement_parent->colour;
                replacement_parent->colour = BLACK;

                sibling->left_pointer->colour = BLACK;
                right_rotate(root,replacement_parent);
                replacement = *root;


            }

        }


    }

    if ( replacement != NULL ) replacement->colour = BLACK;

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
