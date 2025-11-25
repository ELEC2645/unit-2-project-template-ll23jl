#ifndef FUNCS_H
#define FUNCS_H

/* Prototypes mirroring the C++ version */
static void main_menu(void);            /* runs in the main loop */
static void print_main_menu(void);      /* output the main menu description */
static int  get_user_input(void);       /* get a valid integer menu choice */
static void select_menu_item(int input);/* run code based on user's choice */


void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);


static void database_menu(void);
static void print_database_menu(void);
static void select_sub_menu_item(int input);

void submenu_item_1(void);
void submenu_item_2(void);
void submenu_item_3(void);


static void go_back_to_main(void);      /* wait for 'b'/'B' to continue */
static int  is_integer(const char *s);  /* validate integer string */


struct plant {
    char name[50];
    int soil_type;                  // 1-loose          2-chalk         3-loam
    int growth_pattern;             // 1-ground cover   2-climbing      3-upright
    float optimal_temp;             // in degrees Celcius
    float optimal_humidity;         // in percent
    float optimal_light;            // in lumins
    float max_size;                 // in mm
    float growth_speed;             // on a scale of 1 (slow - oak tree) to 10 (fast - algae)
};


#endif