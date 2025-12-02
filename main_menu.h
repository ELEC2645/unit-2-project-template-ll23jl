#ifndef MAIN_MENU_H
#define MAIN_MENU_H

/* structure for a ~plant~ */
struct plant {
    char name[100];
    char soil_type[100];            // sandy, loamy, chalk, clay, etc
    char growth_pattern[100];       // ground cover, climbing, upright, etc
    float optimal_temp;             // in degrees Celcius
    float optimal_humidity;         // in percent
    float optimal_light;            // in lumins
    float max_size;                 // in mm
    float growth_speed;             // on a scale of 1 (slow - oak tree) to 10 (fast - algae)
};

void main_menu(void);         // runs in the main loop
void print_main_menu(void);                  // output the main menu description
void select_menu_item(int input);            // run code based on user's choice
int get_main_menu_input(void);               // get a valid integer menu choice
void go_back_to_main_menu(void); 

void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);

#endif