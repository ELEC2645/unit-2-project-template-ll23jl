//description here please :P ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()

#include "main_menu.h"
#include "submenu.h"
#include "file_handling.h"
#include "funcs.h"


/* runs in menu_item_1 */
void database_menu(void)
{
    print_database_menu();
    {
        int input = get_sub_menu_input();
        select_submenu_item(input);
    }
}

/* output the submenu description */
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

/* run code based on user's choice */
void select_submenu_item(int input)
{
    switch (input) {
        case 1:
            submenu_item_1();
            go_back_to_sub_menu();
            break;
        case 2:
            submenu_item_2();
            go_back_to_sub_menu();
            break;
        case 3:
            submenu_item_3();
            go_back_to_sub_menu();
            break;
        case 4:
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}

/* View plant database */
void submenu_item_1(void) {
    for (int i=0; i<10; i++){
        
    }
    
}

/* Add a plant species */
void submenu_item_2(void) {
    
    struct plant template = {0};
    strcpy(template.name, "name");
    template.soil_type = 0;
    template.growth_pattern = 0;
    template.optimal_temp = 0.0;
    template.optimal_humidity = 0.0;
    template.optimal_light = 0.0;
    template.max_size = 0.0;
    template.growth_speed = 0.0;



}

/* Edit a plant species */
void submenu_item_3(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}


/* Return to the main menu */
void go_back_to_sub_menu(void)
{
    char buf[64];
    do {
        printf("\nEnter 'b' or 'B' to go back to sub menu: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');
}

/* Check user input matches criteria for menu selection and assign to int input*/
int get_sub_menu_input(void)
{
    enum { MENU_ITEMS = 5 };   /* 1..4 = items, 5 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

