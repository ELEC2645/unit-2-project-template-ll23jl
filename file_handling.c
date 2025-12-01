//description here please :) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()

#include "main_menu.h"
#include "submenu.h"
#include "file_handling.h"
#include "funcs.h"



/* extract plant data from open file*/
void retrieve_data(struct plant *array){
    char raw_species_data[100];                             //assume string is 100 characters or less
    
    FILE *database = fopen("plants.csv", "r");

    for (int i=0; i<10; i++){
        fgets(raw_species_data, 100, database);

        for (int j=0; j<8; j++){
            char *token[100];
            strcpy(*token, strtok(raw_species_data, ","));
            
            switch (j){                                         // assigns each column in the data to the corresponding struct feature
                case 0:                                         // assume the data will always be in the correct columns and of correct data type
                    strcpy(array[i].name, *token);
                case 1:
                    array[i].soil_type = atoi(*token);
                case 2:
                    array[i].growth_pattern = atoi(*token);
                case 3:
                    array[i].optimal_temp = atof(*token);
                case 4:
                    array[i].optimal_humidity = atof(*token);
                case 5:
                    array[i].optimal_light = atof(*token);
                case 6:
                    array[i].max_size = atof(*token);
                case 7:
                    array[i].growth_speed = atof(*token);
                default:
                    printf("Error - default \n");
                    go_back_to_main_menu();
            }
        }
    }
    if (fclose(database) != 0) {                                // closes file once finished extracting data
        perror("Error closing file");
    }
    else { 
        printf("File closed.\n");
    }
    
}

/* appends a species to the plant database CSV */
void save_to_database(struct plant *array){
    FILE *plant_database;
    plant_database = fopen("plants.csv", "w");
    for(int i=0; i<10; i++){
        fprintf(plant_database, "%s,%i,%i,%.2f,%.2f,%.2f,%.2f,%.2f", 
            array[i].name, array[i].soil_type, array[i].growth_pattern, 
            array[i].optimal_temp, array[i].optimal_humidity, array[i].optimal_light, 
            array[i].max_size, array[i].growth_speed);
        }
    if (fclose(plant_database) != 0) {                          // closes file once finished extracting data
        perror("Error closing file");
    }
    else { 
        printf("File closed.\n");
    }
}






