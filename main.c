// ELEC2645 Unit 2 Project 
// Command Line Application Menu Handling Code
/* A tool for recording plant species, comparing compatibility and 
for generating miniture ecosystems */

#include <stdio.h>      // for FILE data type

#include "main_menu.h"
#include "submenu.h"
#include "funcs.h"


int main(void)
{
        struct plant plant_array[10];                   // create empty array of plant structures

        struct plant Monstera = (struct plant){"Monstera deliciosa",5,1,17.03,25.72,36.07,54.65,436.5,1332.37,350.56,2.2};
        struct plant Philodendron = (struct plant){"Philodendron hederaceum", 5, 1,15.16,28.8,37.23,79.58,187.09,1930.2,1455.03,6.88};
        struct plant Pothos = (struct plant){"Epipremnum aureum",0,4,14.68,24.6,48.8,77.05,440.08,1676.47,908,2.39};
        struct plant SpiderPlant = (struct plant){"Chlorophytum comosum",7,0,18.3,29.18,46.41,88.4,506.7,870.39,590.04,1.29};
        struct plant PeacyLily = (struct plant){"Spathiphyllum wallisii",2,2,19.5,27.48,64.86,86.5,314.38,450,917.22,8.77};
        struct plant FalseShamrock = (struct plant){"Oxalis triangularis",2,2,27.08,39.4,30.6,58.52,1360.08,1870.5,622.66,3.07};
        struct plant RubberPlant = (struct plant){"Ficus elastica",5,2,21.58,28.6,65.29,86.4,400.6,1095.27,927.68,7.67};
        struct plant JadePlant = (struct plant){"Crassula ovata",1,3,13.2,22.4,62.33,89.4,272.04,450.4,617.02,9.23};
        struct plant PonytailPalm = (struct plant){"Beaucarnea recurvata",1,2,14.5,23.7,52.6,65.75,784.7,1409.87,1631.96,9.75};
        struct plant Pilea = (struct plant){"Pilea peperomioides",5,2,9.4,18.6,20.6,32.96,448.84,975.8,1478.41,1.65};
        
        plant_array[0] = Monstera;
        plant_array[1] = Philodendron;
        plant_array[2] = Pothos;
        plant_array[3] = SpiderPlant;
        plant_array[4] = PeacyLily;
        plant_array[5] = FalseShamrock;
        plant_array[6] = RubberPlant;
        plant_array[7] = JadePlant;
        plant_array[8] = PonytailPalm;
        plant_array[9] = Pilea;
        


        /* this will run forever until exit(0) is called in select_menu_item() */
    for(;;) {
        main_menu(plant_array);
    }


    /* not reached */
    return 0;
}
