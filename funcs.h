#ifndef FUNCS_H
#define FUNCS_H

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


int get_main_menu_input(void);                           // get a valid integer menu choice
void go_back_to_main_menu(void);                         // wait for 'b'/'B' to continue
int  is_integer(const char *s);                     // validate integer string
int get_float (void);


#endif