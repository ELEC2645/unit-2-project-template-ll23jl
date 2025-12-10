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
    
    printf("\n %s \n", array[1].name);
    
    for (int i = 0; i<10; i++){
        print_plant(array, i);    
    };
}

/* Add a plant species */
void submenu_item_2(struct plant *array) {
    
    printf("\nChoose a row to overwrite:");
    for (int i = 0; i<10; i++){printf("\n %d - %s", i, array[i].name);};
    
    int ov_r = get_array_selection();                               
    if(ov_r==-1){return;}                                           // index of plant to overwrite
    printf("\nselected: %d - %s", ov_r, array[ov_r].name);

/* Uses user inputs to retrieve data for each member of the struct: */

    printf("\nEnter new plant details:");
    printf("\n\tName:");
    fgets(array[ov_r].name, 100, stdin);
    array[ov_r].name[strcspn(array[ov_r].name, "\n")] = 0;          // strips \n from end of input string
    printf("\n\tSoil type: \n\t0 = Generic \n\t1 = Sandy, \n\t2 = Dense, \n\t3 = Bark mix, \n\t4 = Bog, \n\t5 = Chunky, \n\t6 = Aquatic, \n\t7 = Light");
    scanf("%d", &array[ov_r].soil_type);
    printf("\n\tGrowth pattern: \n\t0 = Ground cover, \n\t1 = Upright, \n\t2 = Spreading/bushy, \n\t3 = Climbing, \n\t4 = Trailing");
    scanf("%d", &array[ov_r].growth_pattern);
    printf("\n\tMinimum temperature:");
    scanf("%f", &array[ov_r].min_temp);
    printf("\n\tMaximum temperature:");
    scanf("%f", &array[ov_r].max_temp);
    printf("\n\tMinimum humidity:");
    scanf("%f", &array[ov_r].min_humidity);
    printf("\n\tMaximum humidity:");
    scanf("%f", &array[ov_r].max_humidity);
    printf("\n\tMinimum light:");
    scanf("%f", &array[ov_r].min_light);
    printf("\n\tMaximum light:");
    scanf("%f", &array[ov_r].max_light);
    printf("\n\tMax size:");
    scanf("%f", &array[ov_r].max_size);
    printf("\n\tGrowth speed:");
    scanf("%f", &array[ov_r].growth_speed);

    print_plant(array, ov_r);
}

/* Edit a plant species */
void submenu_item_3(struct plant *array) {
    submenu_item_2(array);
    
}


