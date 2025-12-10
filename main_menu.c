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
    printf("\n----------------- Main menu -----------------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t\t1. Plant database\t\t\n"
           "\t\t2. Compare two species\t\t\n"
           "\t\t3. Find compatible partner\t\t\n"
           "\t\t4. Generate vivarium\t\t\n"
           "\t\t5. Exit\t\t\t\t\n"
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
            menu_item_2(array);
            go_back_to_main_menu();
            break;
        case 3:
            menu_item_3(array);
            go_back_to_main_menu();
            break;
        case 4:
            menu_item_4(array);
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
void menu_item_2(struct plant *array) {
    for (int i = 0; i<10; i++){printf("\n %d - %s", i, array[i].name);};
    printf("\nChoose species one:");
    int sp_1 = get_array_selection();               //index of plant 1
    if(sp_1==-1){return;}                           // go back to main menu if "b"||"B" is input
    printf("\nChoose species two:");
    int sp_2 = get_array_selection();               //index of plant 2
    if(sp_2==-1){return;}                           // go back to main menu if "b"||"B" is input

    print_plant(array, sp_1);
    print_plant(array, sp_2); 

    int result = compare(array, sp_1, sp_2);

    if (result == 1){printf("\n\nThese two plants are compatible");}
    else {printf("\n\nThese two plants are not compatible");}    
}

/* Find compatible partner */
void menu_item_3(struct plant *array) {

    struct plant plant_array[10];                  // create empty array of plant structures

    for (int i = 0; i<10; i++){printf("\n %d - %s", i, array[i].name);};
    printf("\nChoose species:");
    int sp = get_array_selection();                 // index of plant 1
    if(sp==-1){return;}                             // go back to main menu if "b"||"B" is input

    int place = 0;                                  // placeholder for the array index


    for (int i = 0; i<10; i++){
        if (i==sp){continue;}                       // skips comparison between chosen plant and itself
        int result = compare(array, sp, i);
        if (result==1){
            plant_array[place] = array[i];          //add compatible plant to array at placeholder index
            place++;
        }
         
    }

    if(place==0){
        printf("There are no compatible plant species");
    }

    else {
        printf("\nCompatible plant species for %s: \n", array[sp].name);
        for (int i = 0; i < place; i++){
            print_plant(plant_array,i);
        }
    }
}

/* Generate vivarium */
void menu_item_4(struct plant *array) {
    k_means(array);
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
