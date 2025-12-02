//description here please :O ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()

#include "main_menu.h"
#include "submenu.h"
#include "funcs.h"

/* runs in the main loop */
void main_menu(struct plant *array)
{   
    print_main_menu();
    {
        int input = get_menu_input();
        select_menu_item(input, array);
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
void select_menu_item(int input, struct plant *array)
{
    switch (input) {
        case 1:
            menu_item_1(array);
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
void menu_item_1(struct plant *array) {
    database_menu(array);
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
