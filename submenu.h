#ifndef SUBMENU_H
#define SUBMENU_H

void database_menu(void);                       // runs in menu_item_1
void print_database_menu(void);                 // output the submenu description
void select_submenu_item(int input);            // run code based on user's choice
int get_sub_menu_input(void);                           // get a valid integer menu choice
void go_back_to_sub_menu(void); 

void submenu_item_1(void);
void submenu_item_2(void);
void submenu_item_3(void);

#endif