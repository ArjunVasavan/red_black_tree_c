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

void print_tree_lines(node* root, char* prefix, int is_left) {
    if (root == NULL) return;

    printf("%s", prefix);
    printf("%s", is_left ? "|-- " : "`-- ");
    printf("%d\n", root->data);

    char new_prefix[256];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix,
             is_left ? "|   " : "    ");

    print_tree_lines(root->left_pointer,  new_prefix, 1);
    print_tree_lines(root->right_pointer, new_prefix, 0);
}
