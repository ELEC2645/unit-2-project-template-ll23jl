#ifndef FUNCS_H
#define FUNCS_H


int get_menu_input(void);                                   // get a valid integer menu choice
void go_back_to_main_menu(void);                            // wait for 'b'/'B' to continue
int  is_integer(const char *s);                             // validate integer string
int get_array_selection(void);                              // 
int compare(struct plant *array, int sp_1, int sp_2);
void print_plant (struct plant *array, int sp);
char* get_soil_type (struct plant *array, int i);
char* get_growth_pattern (struct plant *array, int i);
void k_means (struct plant *array);    
float eucl_dis (struct plant *array, int sp, struct plant *centroid, int ct);

#endif