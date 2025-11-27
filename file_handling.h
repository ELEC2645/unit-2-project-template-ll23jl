#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

FILE open_database(struct plant *array);                           // opens plant database csv
void close_database(FILE *data);                    // closes the open database

void retrieve_data(FILE *database, struct plant * plant_array);                           // reads csv file with previsouly loaded plants and updates empty structs
void save_to_database(struct plant *species);       // saves additional/edited plants to csv


#endif