//description here please :O ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()

#include "main_menu.h"
#include "submenu.h"
#include "file_handling.h"
#include "funcs.h"

/* runs in the main loop */
void main_menu(void)
{   
    
    print_main_menu();
    {
        int input = get_main_menu_input();
        select_menu_item(input);
    }




}

/* output the main menu description */
void print_main_menu(void)
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

/* run code based on user's choice */
void select_menu_item(int input)
{
    switch (input) {
        case 1:
            menu_item_1();
            go_back_to_main_menu();
            break;
        case 2:
            menu_item_2();
            go_back_to_main_menu();
            break;
        case 3:
            menu_item_3();
            go_back_to_main_menu();
            break;
        case 4:
            menu_item_4();
            go_back_to_main_menu();
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}

/* Navigate to sub menu for plant database */
void menu_item_1(void) {
    database_menu();
}

/* Compare two species' compatibility */
void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}

/* Find compatible partner */
void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

/* Generate vivarium */
void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}

/* Return to the main menu */
void go_back_to_main_menu(void)
{
    char buf[64];
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');
}

/* Check user input matches criteria for menu selection and assign to int input*/
int get_main_menu_input(void)
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

