#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

/* structure for a ~plant~ */
struct plant {
    char name[100];
    int soil_type;                  // 1-loose          2-chalk         3-loam
    int growth_pattern;             // 1-ground cover   2-climbing      3-upright
    float optimal_temp;             // in degrees Celcius
    float optimal_humidity;         // in percent
    float optimal_light;            // in lumins
    float max_size;                 // in mm
    float growth_speed;             // on a scale of 1 (slow - oak tree) to 10 (fast - algae)
};

FILE* open_database();                           // opens plant database csv
void close_database(FILE *data);                    // closes the open database

void retrieve_data(struct plant *array);                           // reads csv file with previsouly loaded plants and updates empty structs
void save_to_database(struct plant *array);       // saves additional/edited plants to csv


#endif