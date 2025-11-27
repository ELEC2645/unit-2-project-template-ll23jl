//description here please :) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()

#include "main_menu.h"
#include "submenu.h"
#include "file_handling.h"
#include "funcs.h"

FILE open_database(struct plant *array){
    FILE *plant_database;
    plant_database = fopen("plants.csv", "r");

    retrieve_data(plant_database, array);
    submenu_item_1();
    return *plant_database;

}

void close_database(FILE *data){
    if (fclose(data) != 0) {
        perror("Error closing file");
    }
    else { 
        printf("File closed.\n");
    }
}


/* extract plant data from open file*/
void retrieve_data(FILE *database, struct plant *plant_array){
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
                    go_back_to_main_menu();
            }
        }
    }
    
}

/* appends a species to the plant database CSV */
void save_to_database(struct plant *species){
    FILE *plant_database;
    plant_database = fopen("plants.csv", "w");
    for(int i=0; i<10; i++){
        fprintf(plant_database, "%s,%i,%i,%.2f,%.2f,%.2f,%.2f,%.2f", 
            species->name, species->soil_type, species->growth_pattern, 
            species->optimal_temp, species->optimal_humidity, species->optimal_light, 
            species->max_size, species->growth_speed);
        }
}






