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

void print_tree(node* root) {

    if ( root == NULL ) {
        printf("Tree is Empty\n");
        return;
    }

    node* queue[1024];

    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        int level_size = rear - front;

        for ( int i = 0 ; i < level_size ; i++ ) {

            node* curr = queue[front++];

            printf("%d(%s) ",curr->data,curr->colour == RED ? "R" : "B" );

            if (curr->left_pointer != NULL) {
                queue[rear++] = curr->left_pointer;
            }
            if ( curr->right_pointer != NULL ) {
                queue[rear++] = curr->right_pointer;
            }

        }

        printf("\n");
    }


}
