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
        struct plant *plant_array[10];                   // create empty array of plant structure pointers

        struct plant Monstera = (struct plant){"Monstera deliciosa","sandy","upright",17.9,36.07,1332.37,350.56,2.2};
        struct plant Philodendron = (struct plant){"Philodendron hederaceum", "chalk", "upright",18.16,37.23,847.09,1455.03,6.88};
        struct plant Pothos = (struct plant){"Epipremnum aureum","chalk","upright",20.68,77.05,340.08,1176.47,2.39};
        struct plant SpiderPlant = (struct plant){"Chlorophytum comosum","sandy","spreading",29.18,46.41,870.39,590.04,1.29};
        struct plant PeacyLily = (struct plant){"Spathiphyllum wallisii","peaty","spreading",27.48,64.86,314.38,917.22,8.77};
        struct plant FalseShamrock = (struct plant){"Oxalis triangularis","sandy","upright",27.08,78.52,1360.08,622.66,3.07};
        struct plant RubberPlant = (struct plant){"Ficus elastica","sandy","climbing",21.58,65.29,1095.27,927.68,7.67};
        struct plant JadePlant = (struct plant){"Crassula ovata","clay","bushy",22.4,62.33,272.04,617.02,9.23};
        struct plant PonytailPalm = (struct plant){"Beaucarnea recurvata","sandy","bushy",23.7,65.75,1409.87,1631.96,9.75};
        struct plant Pilea = (struct plant){"Pilea peperomioides","chalk","ground cover",18.6,32.96,448.84,1478.41,1.65};
        
        plant_array[0] = &Monstera;
        plant_array[1] = &Philodendron;
        plant_array[2] = &Pothos;
        plant_array[3] = &SpiderPlant;
        plant_array[4] = &PeacyLily;
        plant_array[5] = &FalseShamrock;
        plant_array[6] = &RubberPlant;
        plant_array[7] = &JadePlant;
        plant_array[8] = &PonytailPalm;
        plant_array[9] = &Pilea;
        
        /* this will run forever until exit(0) is called in select_menu_item() */
    for(;;) {
        main_menu(*plant_array);
    }


    /* not reached */
    return 0;
}
