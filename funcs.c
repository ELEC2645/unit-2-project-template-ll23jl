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
    
    printf("Soil: \n\t%s - %s \n\t%s - %s", array[sp_1].name,array[sp_1].soil_type, array[sp_2].name, array[sp_2].soil_type);

    if (strcmp(array[sp_1].soil_type,array[sp_2].soil_type)){return 0;}     // compares two
    else {return 1;}
}



// ------------------ K-means clustering functions ------------------

void k_means (void){
    int k = 5;                              // number of clusters I want to sort data into
    int n = 7;                              // number of features of the dataset

    struct plant centroid_1 = (struct plant){"Centroid 1","N/A","N/A",18.6,32.96,448.84,1478.41,1.65};          // change these values later to be randomised and spread out
    struct plant centroid_2 = (struct plant){"Centroid 2","N/A","N/A",18.6,32.96,448.84,1478.41,1.65};          // alternatively, use roughly correct values for a particular habitat as centroid
    struct plant centroid_3 = (struct plant){"Centroid 3","N/A","N/A",18.6,32.96,448.84,1478.41,1.65};          // eg: river bank, woodland, marsh, tropical beach, etc.
    struct plant centroid_4 = (struct plant){"Centroid 4","N/A","N/A",18.6,32.96,448.84,1478.41,1.65};
    struct plant centroid_5 = (struct plant){"Centroid 5","N/A","N/A",18.6,32.96,448.84,1478.41,1.65};


}


float eucl_dis (struct plant *array, int sp_1, struct plant centroid){

    float sum = square(array[sp_1].optimal_humidity - centroid.optimal_humidity)
              - square(array[sp_1].optimal_temp - centroid.optimal_temp)
              - square(array[sp_1].optimal_light - centroid.optimal_light);
    float distance = sqrt(sum);
    return distance;
}




