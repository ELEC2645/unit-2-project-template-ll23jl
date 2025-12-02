#ifndef SUBMENU_H
#define SUBMENU_H

void database_menu(struct plant *array);                       // runs in menu_item_1
void print_sub_menu(void);                 // output the submenu description
void select_submenu_item(int input, struct plant *array);            // run code based on user's choice
int get_sub_menu_input(void);                           // get a valid integer menu choice

void submenu_item_1(struct plant *array);
void submenu_item_2(void);
void submenu_item_3(void);

#endif