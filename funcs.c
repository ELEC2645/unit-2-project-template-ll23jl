//description here please :3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()
#include <math.h>       // for sqrt()

#include "main_menu.h"
#include "submenu.h"
#include "funcs.h"



/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}

/* Check user input matches criteria for menu selection and assign to int input */
int get_menu_input(void)
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

/* Check user input matches criteria for menu selection and assign to int input */
int get_array_selection(void)
{
    enum { MENU_ITEMS = 9 };   /* 1..4 = items, 5 = Exit */
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
            if(buf[0]=='b'||buf[0]=='b'){
                return -1; 
                }
            else{
            printf("Enter an integer!\n");
            valid_input = 0;
            }
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 0 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

/* Takes plant array and two plant indexes and compares the two plants, outputs a 1 or 0 */
int compare(struct plant *array, int sp_1, int sp_2){
    
    if (array[sp_1].soil_type != array[sp_2].soil_type)
        {return 0;}             // compares soil types. returns 0 if they don't match

    else if (array[sp_1].min_temp>array[sp_2].max_temp||array[sp_2].min_temp>array[sp_1].max_temp)
        {return 0;}             // check for overlap of temperatures, if none, returns 0

    else if (array[sp_1].min_humidity>array[sp_2].max_humidity||array[sp_2].min_humidity>array[sp_1].max_humidity)
        {return 0;}             // check for overlap of humidity levels, if none, returns 0

    else if (array[sp_1].min_light>array[sp_2].max_light||array[sp_2].min_light>array[sp_1].max_light)
        {return 0;}             // check for overlap of light levels, if none, returns 0


    else {return 1;}            // if all statements above false, returns 1
}

/* Prints plant species characteristics to terminal */
void print_plant (struct plant *array, int sp){
    printf("\n\n%s; \n\tsoil type: \t\t\t%s; \n\tgrowth pattern: \t\t%s; \n\tmin temperature: \t\t%.2f \u00B0C; \n\tmax temperature: \t\t%.2f \u00B0C;"
                "\n\tmin humidity: \t\t\t%.2f %%; \n\tmax humidity: \t\t\t%.2f %%; \n\tmin light conditions: \t\t%.0f lm;" 
            "\n\tmax light conditions: \t\t%.0f lm; \n\tmaximum size: \t\t\t%.2f mm; \n\tgrowth speed: \t\t\t%.2f /10",
            array[sp].name, get_soil_type(array,sp), get_growth_pattern(array,sp), array[sp].min_temp, array[sp].max_temp, 
            array[sp].min_humidity,array[sp].max_humidity,array[sp].min_light,array[sp].max_light,array[sp].max_size,array[sp].growth_speed);
}

char* get_growth_pattern (struct plant *array, int i){
    switch (array[i].growth_pattern){
        case 0:
            return "Ground cover";
        case 1:
            return "Upright";
        case 2:
            return "Spreading/bushy";
        case 3:
            return "Climbing";
        case 4:
            return "Trailing";
    }
}

char* get_soil_type (struct plant *array, int i){
    switch (array[i].soil_type){
        case 0:
            return "Generic";
        case 1:
            return "Sandy";
        case 2:
            return "Dense";
        case 3:
            return "Bark mix";
        case 4:
            return "Bog";
        case 5:
            return "Chunky";
        case 6:
            return "Aquatic";
        case 7:
            return "Light";
    }
}



// ------------------ K-means clustering functions ------------------

void k_means (struct plant *array){


    int k = 5;                              // number of clusters I want to sort data into
    int n = 7;                              // number of features of the dataset

    struct plant centroid[k];               // array of centroid plant structs

    
    // ------------- this array MUST have equal/more elements than chosen k value! -------------
    

    for(int i=0; i<k; i++){
        centroid[i].soil_type = rand() % (8);
        centroid[i].growth_pattern = rand() % (5);
        centroid[i].min_temp = rand() % (31);
        centroid[i].max_temp = rand() % (51);
        centroid[i].min_light = rand() % (1502);
        centroid[i].max_light = rand() % (7001);
        centroid[i].min_humidity = rand() % (60-30+1+30);
        centroid[i].max_humidity = rand() % (101);
        centroid[i].max_size = rand() % (2501);
        centroid[i].growth_speed = rand() % (11);
    }

    for(int i=0; i<k; i++){ 
    print_plant(centroid,i);
    }

    

}


float eucl_dis (struct plant *array, int sp_1, struct plant centroid){

    float sum = 0.8;
    float distance = sqrt(sum);
    return distance;
}



