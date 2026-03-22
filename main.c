#include "include/rbtree.h"

int main(int argc, char** argv) {

    node* root = NULL;
    int choice;
    int value;

    do {

        print_menu();
        scanf("%d",&choice);

        switch (choice) {
            case 1: {
                printf("Enter the value: ");
                scanf("%d", &value);
                insert(&root, value);
                break;
            }
            case 2: {
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_node(&root, value);
                break;
            }
            case 3: {
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(&root, value);
                break;
            }
            case 4: {
                find_min_wrapper(root);
                break;
            }
            case 5: {
                find_max_wrapper(root);
                break;
            }
            case 6: {
                delete_min(&root);
                break;
            }
            case 7: {
                delete_max(&root);
                break;
            }
            case 8: {
                print_tree(root);
                printf("\n");
                break;
            }
            case 9: {
                exit(EXIT_SUCCESS);
            }
        }

    }while (1);
}
