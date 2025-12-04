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
        int input = get_menu_input();
        select_submenu_item(input, array);
    }
}

/* output the submenu description */
void print_sub_menu(void)
{
    printf("\n--------------- Database menu ---------------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t\t1. View plant database\t\n"
           "\t\t2. Add a plant species\t\n"
           "\t\t3. Edit a plant species\t\n"
           "\t\t4. Return to main menu\t\t\n"
           "\t\t5. Exit program\t\t\t\t\n"
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
            submenu_item_2(array);
            break;
        case 3:
            submenu_item_3(array);
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
        printf("\n\n%s; \n\tsoil type: \t\t\t\t%s; \n\tgrowth pattern: \t\t\t%s; \n\toptimal temperature: \t\t\t%.2f \u00B0C; \n\toptimal humidity: \t\t\t%.2f %%;" 
            "\n\toptimal light conditions: \t\t%.0f lm; \n\tmaximum size: \t\t\t\t%.2f mm; \n\tgrowth speed: \t\t\t\t%.2f /10.",
            array[i].name, array[i].soil_type, array[i].growth_pattern, array[i].optimal_temp, 
            array[i].optimal_humidity,array[i].optimal_light,array[i].max_size,array[i].growth_speed);
        };
}

/* Add a plant species */
void submenu_item_2(struct plant *array) {
    
    printf("\nChoose a row to overwrite:");
    for (int i = 0; i<10; i++){printf("\n %d - %s", i, array[i].name);};
    
    int ov_r = get_array_selection();                               //index of plant to overwrite
    if(ov_r==-1){return;}
    printf("\nselected: %d - %s", ov_r, array[ov_r].name);

    printf("\nEnter new plant details:");
    printf("\n\tName:");
    fgets(array[ov_r].name, 100, stdin);
    printf("\n\tSoil type:");
    fgets(array[ov_r].soil_type, 100, stdin);
    printf("\n\tGrowth pattern:");
    fgets(array[ov_r].growth_pattern, 100, stdin);
    printf("\n\tOptimal temperature:");
    scanf("%f", &array[ov_r].optimal_temp);
    printf("\n\tOptimal humidity:");
    scanf("%f", &array[ov_r].optimal_humidity);
    printf("\n\tOptimal light:");
    scanf("%f", &array[ov_r].optimal_light);
    printf("\n\tMax size:");
    scanf("%f", &array[ov_r].max_size);
    printf("\n\tGrowth speed:");
    scanf("%f", &array[ov_r].growth_speed);

    printf("\nNew plant details:\n\n%s; \n\tsoil type: \t\t\t\t%s; \n\tgrowth pattern: \t\t\t%s; \n\toptimal temperature: \t\t\t%.2f \t%cC; \n\toptimal humidity: \t\t\t%.2f \t%%;" 
            "\n\toptimal light conditions: \t\t%.0f \tlm; \n\tmaximum size: \t\t\t\t%.2f \tmm; \n\tgrowth speed: \t\t\t\t%.2f \t/10.",
            array[ov_r].name, array[ov_r].soil_type, array[ov_r].growth_pattern, array[ov_r].optimal_temp, 176, 
            array[ov_r].optimal_humidity,array[ov_r].optimal_light,array[ov_r].max_size,array[ov_r].growth_speed);

}

/* Edit a plant species */
void submenu_item_3(struct plant *array) {
    submenu_item_2(array);
    
}


