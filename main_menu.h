#ifndef MAIN_MENU_H
#define MAIN_MENU_H

/* structure for a ~plant~ */
struct plant {
    char name[100];
    int soil_type;                  // 0 = Generic 1 = Sandy, 2 = Dense, 3 = Bark mix, 4 = Bog, 5 = Chunky, 6 = Aquatic, 7 = Light
    int growth_pattern;             // 0 = Ground cover, 1 = Upright, 2 = Spreading/bushy, 3 = Climbing, 4 = Trailing
    float min_temp;                 // in degrees Celcius
    float max_temp;                 // in degrees Celcius
    float min_humidity;             // in percent
    float max_humidity;             // in percent
    float min_light;                // in lumens
    float max_light;                // in lumens
    float max_size;                 // in mm
    float growth_speed;             // on a scale of 1 (slow - oak tree) to 10 (fast - algae)
};

void main_menu(struct plant *array);                                // runs in the main loop
void print_main_menu(void);                                         // output the main menu description
void select_menu_item(int input, struct plant *array);              // run code based on user's choice
void go_back_to_main_menu(void); 

void menu_item_1(struct plant *array);
void menu_item_2(struct plant *array);
void menu_item_3(struct plant *array);
void menu_item_4(struct plant *array);

#endif