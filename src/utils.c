#include "../include/rbtree.h"

void inorder(node* root) {

    if ( root == NULL ) {
        return;
    }

    inorder(root->left_pointer);

    printf("%d ",root->data);

    inorder(root->right_pointer);

}

void print_menu() {

        printf("===============================\n");
        printf("   RED BLACK TREE OPERATIONS\n");
        printf("===============================\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Delete Minimum\n");
        printf("7. Delete Maximum\n");
        printf("8. Display Tree\n");
        printf("9. Exit\n");
        printf("===============================\n");
        printf("Enter your choice:\n");

}
