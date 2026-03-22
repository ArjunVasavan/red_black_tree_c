#include "include/rbtree.h"

int main(int argc, char** argv) {

    node* root = NULL;
    char choice;
    int value;

    do {

        print_menu();
        scanf("%c",&choice);

        switch (choice) {

            case 1:{

                printf("Enter the value: ");
                scanf("%d",&value);
                insert(&root,value);
                break;
            }
            case 2:{

                printf("Enter value to delete: ");
                scanf("%d",&value);
                delete_node(&root,value);
                break;
            }
            case 3:{ // Search


                break;
            }
            case 4:{ // Find min 
                find_min_wrapper(root);
                break;
            }
            case 5:{ // find max

                find_max_wrapper(root);
                break;
            }
            case 6:{ // display tree

                break;
            }
            case 7:{ //exit

                break;
            }
        }

    }while (1);
}
