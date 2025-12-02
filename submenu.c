//description here please :P ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()

#include "main_menu.h"
#include "submenu.h"
#include "funcs.h"


/* runs in menu_item_1 */
void database_menu(struct plant *array)
{
    print_sub_menu();
    {
        int input = get_sub_menu_input();
        select_submenu_item(input, array);
    }
}

/* output the submenu description */
void print_sub_menu(void)
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
void select_submenu_item(int input, struct plant *array)
{
    switch (input) {
        case 1:
            submenu_item_1(array);
            break;
        case 2:
            submenu_item_2();
            break;
        case 3:
            submenu_item_3();
            break;
        case 4:
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}

/* View plant database */
void submenu_item_1(struct plant *array) {
    for (int i = 0; i<10; i++){
        printf("\n\n%s; \n\tsoil type: \t\t\t\t%s; \n\tgrowth pattern: \t\t\t%s, \n\toptimal temperature: \t\t\t%.2f \t%cC; \n\toptimal humidity: \t\t\t%.2f \t%%;" 
            "\n\toptimal light conditions: \t\t%.0f \tlm; \n\tmaximum size: \t\t\t\t%.2f \tmm; \n\tgrowth speed: \t\t\t\t%.2f \t/10.",
            array[i].name, array[i].soil_type, array[i].growth_pattern, array[i].optimal_temp, 176, 
            array[i].optimal_humidity,array[i].optimal_light,array[i].max_size,array[i].growth_speed);
        }
}

/* Add a plant species */
void submenu_item_2(void) {
    
    struct plant template = {0};
    strcpy(template.name, "name");
    strcpy(template.soil_type, "soil type");
    strcpy(template.growth_pattern, "growth pattern");
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

