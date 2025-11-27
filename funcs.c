


#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()

#include "funcs.h"
#include "submenu.h"

struct plant plant_array[10];       //array of 10 empty plant structures


/* Navigate to sub menu for plant database */
void menu_item_1(void) {
    database_menu();
}

/* Compare two species' compatibility */
void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 2 */
}

/* Find compatible partner */
void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

/* Generate vivarium */
void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}


/* View plant database */
void submenu_item_1(void) {
    for (int i=0; i<10; i++){
        //printf("%s", plant_array[i].name);
    }
    
}

/* Add a plant species */
void submenu_item_2(void) {
    
    struct plant template = {0};
    strcpy(template.name, "name");
    template.soil_type = 0;
    template.growth_pattern = 0;
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

/* Return to the main menu */
void go_back_to_main(void)
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


int get_float(void){

    float num;
    
    scanf("%f", &num);

    return num;
}

/* opens plant database CSV and checks how many lines */
int get_num_species (void){

}


void open_database(void){
    FILE *plant_database;
    plant_database = fopen("plants.csv", "r");
}


/* extract plant data from open file*/
void retrieve_data(FILE *database){
    char raw_species_data[100];                             //assume string is 100 characters or less
    
    for (int i=0; i<10; i++){
        fgets(raw_species_data, 100, database);

        for (int j=0; j<8; j++){
            char *token[100];
            strcpy(*token, strtok(raw_species_data, ","));
            
            switch (j){
                case 0:
                    strcpy(plant_array[i].name, *token);
                case 1:
                    plant_array[i].soil_type = atoi(*token);
                case 2:
                    plant_array[i].growth_pattern = atoi(*token);
                case 3:
                    plant_array[i].optimal_temp = atof(*token);
                case 4:
                    plant_array[i].optimal_humidity = atof(*token);
                case 5:
                    plant_array[i].optimal_light = atof(*token);
                case 6:
                    plant_array[i].max_size = atof(*token);
                case 7:
                    plant_array[i].growth_speed = atof(*token);
                default:
                    printf("Error - default \n");
                    go_back_to_main();
            }
        }



        
    }
    
}

/* appends a species to the plant database CSV */
void save_to_database(struct plant *species){
    FILE *plant_database;
    plant_database = fopen("plants.csv", "a");
    fprintf(plant_database, "%s,%i,%i,%.2f,%.2f,%.2f,%.2f,%.2f", 
        species->name, species->soil_type, species->growth_pattern, 
        species->optimal_temp, species->optimal_humidity, species->optimal_light, 
        species->max_size, species->growth_speed);
}



