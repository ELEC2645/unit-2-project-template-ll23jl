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
    
    struct plant plant_array[10];                   // create empty array of plant structures

    retrieve_data(plant_array);                     // populates array with data currently in CSV

        /* this will run forever until exit(0) is called in select_menu_item() */
    for(;;) {
        main_menu(plant_array);
    }

    save_to_database(plant_array);                  // stores modified array data back over the CSV



    /* not reached */
    return 0;
}
