#include "include/rbtree.h"
#include <stdio.h>

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
            case 3:{

                break;
            }
            case 4:{

                break;
            }
            case 5:{

                break;
            }
            case 6:{

                break;
            }
        }


    }while (1);

}
