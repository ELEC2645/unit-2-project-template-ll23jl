#ifndef FUNCS_H
#define FUNCS_H


int get_menu_input(void);                                   // get a valid integer menu choice
void go_back_to_main_menu(void);                            // wait for 'b'/'B' to continue
int  is_integer(const char *s);                             // validate integer string
int get_array_selection(void);                              // 
int compare(struct plant *array, int sp_1, int sp_2);       
float eucl_dis (struct plant *array, int sp_1, struct plant centroid)


#endif