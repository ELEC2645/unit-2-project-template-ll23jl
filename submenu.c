


#include <stdio.h>
#include <stdlib.h>     // for exit()

#include "funcs.h"
#include "submenu.h"


void database_menu(void)
{
    print_database_menu();
    {
        int input = get_menu_input();
        select_submenu_item(input);
    }
}


void print_database_menu(void)
{
    printf("\n----------- Database menu -----------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. View plant database\t\n"
           "\t2. Add a plant species\t\n"
           "\t3. Edit a plant species\t\n"
           "\t4. Return to main menu\t\t\n"
           "\t5. Exit program\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}


void select_submenu_item(int input)
{
    switch (input) {
        case 1:
            submenu_item_1();
            go_back_to_main();
            break;
        case 2:
            submenu_item_2();
            go_back_to_main();
            break;
        case 3:
            submenu_item_3();
            go_back_to_main();
            break;
        case 4:
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}