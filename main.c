// ELEC2645 Unit 2 Project 
// Command Line Application Menu Handling Code
/* A tool for recording plant species, comparing compatibility and 
for generating miniture ecosystems */

#include <stdio.h>      // for FILE data type

#include "main_menu.h"
#include "submenu.h"
#include "file_handling.h"
#include "funcs.h"


int main(void)
{
    
    struct plant plant_array[10];                   //create empty array of plant structures

    FILE plant_database = open_database(&plant_array);



        /* this will run forever until exit(0) is called in select_menu_item() */
    for(;;) {
        main_menu();
    }

    /* not reached */
    return 0;
}
