#ifndef MAIN_MENU_H
#define MAIN_MENU_H


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