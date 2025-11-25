// ELEC2645 Unit 2 Project Template
// Command Line Application Menu Handling Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcs.h"
#include "submenu.c"


int main(void)
{
    /* this will run forever until we call exit(0) in select_menu_item() */
    for(;;) {
        main_menu();
    }
    /* not reached */
    return 0;
}

static void main_menu(void)
{
    print_main_menu();
    {
        int input = get_user_input();
        select_menu_item(input);
    }
}


static void print_main_menu(void)
{
    printf("\n----------- Main menu -----------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. Plant database\t\t\n"
           "\t2. Compare two species\t\t\n"
           "\t3. Find compatible partner\t\t\n"
           "\t4. Generate vivarium\t\t\n"
           "\t5. Exit\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}


static void select_menu_item(int input)
{
    switch (input) {
        case 1:
            database_menu();
            go_back_to_main();
            break;
        case 2:
            menu_item_2();
            go_back_to_main();
            break;
        case 3:
            menu_item_3();
            go_back_to_main();
            break;
        case 4:
            menu_item_4();
            go_back_to_main();
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}