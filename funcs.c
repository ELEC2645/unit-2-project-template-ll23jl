//description here please :3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>     // for exit() // for atoi() and atof()
#include <string.h>     // for strcspn()
#include <ctype.h>      // for isdigit()
#include <math.h>       // for sqrt()

#include "main_menu.h"
#include "submenu.h"
#include "funcs.h"



/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}

/* Check user input matches criteria for menu selection and assign to int input */
int get_menu_input(void)
{
    enum { MENU_ITEMS = 5 };   /* 1..4 = items, 5 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

/* Check user input matches criteria for menu selection and assign to int input */
int get_array_selection(void)
{
    enum { MENU_ITEMS = 9 };   /* 1..4 = items, 5 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';
        

        if (!is_integer(buf)) {
            if(buf[0]=='b'||buf[0]=='b'){
                return -1; 
                }
            else{
            printf("Enter an integer!\n");
            valid_input = 0;
            }
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 0 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

/* Takes plant array and two plant indexes and compares the two plants, outputs a 1 or 0 */
int compare(struct plant *array, int sp_1, int sp_2){
    
    if (array[sp_1].soil_type != array[sp_2].soil_type)
        {return 0;}             // compares soil types. returns 0 if they don't match

    else if (array[sp_1].min_temp>array[sp_2].max_temp||array[sp_2].min_temp>array[sp_1].max_temp)
        {return 0;}             // check for overlap of temperatures, if none, returns 0

    else if (array[sp_1].min_humidity>array[sp_2].max_humidity||array[sp_2].min_humidity>array[sp_1].max_humidity)
        {return 0;}             // check for overlap of humidity levels, if none, returns 0

    else if (array[sp_1].min_light>array[sp_2].max_light||array[sp_2].min_light>array[sp_1].max_light)
        {return 0;}             // check for overlap of light levels, if none, returns 0


    else {return 1;}            // if all statements above false, returns 1
}

/* Prints plant species characteristics to terminal */
void print_plant (struct plant *array, int sp){
    printf("\n\n%s; \n\tsoil type: \t\t\t%s; \n\tgrowth pattern: \t\t%s; \n\tmin temperature: \t\t%.2f \u00B0C; \n\tmax temperature: \t\t%.2f \u00B0C;"
                "\n\tmin humidity: \t\t\t%.2f %%; \n\tmax humidity: \t\t\t%.2f %%; \n\tmin light conditions: \t\t%.0f lm;" 
            "\n\tmax light conditions: \t\t%.0f lm; \n\tmaximum size: \t\t\t%.2f mm; \n\tgrowth speed: \t\t\t%.2f /10",
            array[sp].name, get_soil_type(array,sp), get_growth_pattern(array,sp), array[sp].min_temp, array[sp].max_temp, 
            array[sp].min_humidity,array[sp].max_humidity,array[sp].min_light,array[sp].max_light,array[sp].max_size,array[sp].growth_speed);
}

/* Match plant growth pattern int with corresponding growth pattern as a string for printing */
char* get_growth_pattern (struct plant *array, int i){
    switch (array[i].growth_pattern){
        case 0:
            return "Ground cover";
        case 1:
            return "Upright";
        case 2:
            return "Spreading/bushy";
        case 3:
            return "Climbing";
        default:
            return "Trailing";
    }
}

/* Match plant soil type int with corresponding soil type as a string for printing */
char* get_soil_type (struct plant *array, int i){
    switch (array[i].soil_type){
        case 0:
            return "Generic";
        case 1:
            return "Sandy";
        case 2:
            return "Dense";
        case 3:
            return "Bark mix";
        case 4:
            return "Bog";
        case 5:
            return "Chunky";
        case 6:
            return "Aquatic";
        default:
            return "Light";
    }
}



// ------------------ K-means clustering functions ------------------

void k_means (struct plant *array){


    int k = 5;                              // number of clusters I want to sort data into ------ MUST be < 4
    struct plant centroid[k];               // array of centroid plant structs
    struct plant old_centroid[k];           // array of centroid plant structs
    struct plant clusters[k][10];           // array of plants within an array (clusters)
    int centroid_index[k];                  // create array of zeros of size k
     

    
    // ------------- Generation of starting centroids -------------
    for(int i=0; i<k; i++){
        sprintf(centroid[i].name, "Centroid %d", i);
        centroid[i].soil_type = rand() % (8);
        centroid[i].growth_pattern = rand() % (5);
        centroid[i].min_temp = rand() % (31);
        centroid[i].max_temp = rand() % (51);
        centroid[i].min_light = rand() % (1502);
        centroid[i].max_light = rand() % (7001);
        centroid[i].min_humidity = rand() % (60-30+1+30);
        centroid[i].max_humidity = rand() % (101);
        centroid[i].max_size = rand() % (2501);
        centroid[i].growth_speed = rand() % (11);
    }

        int conv = 0;           // sets convergence variable to 0

    // ------------- Runs until centroid values converge -------------
    while (conv == 0){

        memset(centroid_index, 0, k * sizeof(int));         // sets all indexes to zero
        memset(clusters, 0, sizeof(clusters));              // empties clusters


        // sets current centroid values to old centroid array
        for (int cen = 0; cen < k; cen++){
            old_centroid[cen] = centroid[cen];
        }


        // ------------- Assign plants to closest centroid -------------
        for (int plant = 0; plant < 10; plant++){

            int closest_centroid = 0;           // set closest centroid to 0 for each new plant
            float old_dis = 100000;             // set distances to large number for each new plant
            float new_dis = 100000;

            // calculate which centroid is closest to current plant
            for (int cen = 0; cen < k; cen++){
                new_dis = eucl_dis(array, plant, centroid, cen);

                if (new_dis < old_dis) {
                    closest_centroid = cen;
                    old_dis = new_dis;
                }
                
            }

            // assign plant to the array of its closest centroid
            clusters[closest_centroid][centroid_index[closest_centroid]] = array[plant];
            
            // increment centroid_index
            centroid_index[closest_centroid]++;
        }


        // ------------- Calculate new centroids -------------

        for (int clus = 0; clus < k; clus++){
            
            if (centroid_index[clus] == 0) {
                // Reassign empty cluster centroid to a random plant
                centroid[clus] = array[rand() % 10];
                continue;
            }

            // set centroid features to zeros
            
            centroid[clus].soil_type = 0;
            centroid[clus].growth_pattern = 0;
            centroid[clus].min_temp = 0;
            centroid[clus].max_temp = 0;
            centroid[clus].min_light = 0;
            centroid[clus].max_light = 0;
            centroid[clus].min_humidity = 0;
            centroid[clus].max_humidity = 0;
            centroid[clus].max_size = 0;
            centroid[clus].growth_speed = 0;

            // calculate new values by the mean value

            // sum features in the cluster
            for (int index = 0; index < centroid_index[clus]; index++){
                centroid[clus].soil_type += clusters[clus][index].soil_type;
                centroid[clus].growth_pattern += clusters[clus][index].growth_pattern;
                centroid[clus].min_temp += clusters[clus][index].min_temp;
                centroid[clus].max_temp += clusters[clus][index].max_temp;
                centroid[clus].min_humidity += clusters[clus][index].min_humidity;
                centroid[clus].max_humidity += clusters[clus][index].max_humidity;
                centroid[clus].min_light += clusters[clus][index].min_light;
                centroid[clus].max_light += clusters[clus][index].max_light;
                centroid[clus].max_size += clusters[clus][index].max_size;
                centroid[clus].growth_speed += clusters[clus][index].growth_speed;
            }

            // divide features by number of items in the cluster (to find mean)
            centroid[clus].soil_type /= centroid_index[clus];
            centroid[clus].growth_pattern /= centroid_index[clus];
            centroid[clus].min_temp /= centroid_index[clus]; 
            centroid[clus].max_temp /= centroid_index[clus];  
            centroid[clus].min_humidity /= centroid_index[clus];  
            centroid[clus].max_humidity /= centroid_index[clus];  
            centroid[clus].min_light /= centroid_index[clus];  
            centroid[clus].max_light /= centroid_index[clus];  
            centroid[clus].max_size /= centroid_index[clus];  
            centroid[clus].growth_speed /= centroid_index[clus];  

        }

        // ------------- Calculate comparison for convergence -------------

        conv = 1;  // assume converged


        // check old centroid and current centroid match:
        for (int cen = 0; cen < k; cen++) {
            if (centroid[cen].soil_type     != old_centroid[cen].soil_type    ||
                centroid[cen].growth_pattern!= old_centroid[cen].growth_pattern||
                centroid[cen].min_temp      != old_centroid[cen].min_temp     ||
                centroid[cen].min_humidity  != old_centroid[cen].min_humidity ||
                centroid[cen].min_light     != old_centroid[cen].min_light    ||
                centroid[cen].max_humidity  != old_centroid[cen].max_humidity ||
                centroid[cen].max_light     != old_centroid[cen].max_light    ||
                centroid[cen].max_temp      != old_centroid[cen].max_temp     ||
                centroid[cen].max_size      != old_centroid[cen].max_size     ||
                centroid[cen].growth_speed  != old_centroid[cen].growth_speed)
            {
                conv = 0;
                break;  // no need to check more
            }
        }
    }


    // ------------- Print clusters -------------
    
    for (int clus = 0; clus < k; clus++){
        printf("\nCluster %d:",clus);
        for (int i = 0; i < centroid_index[clus]; i++){
            printf("\n\t %s",clusters[clus][i].name);
        }
    }
}

/* Calculates the euclidean distance between a plant and a centroid */
float eucl_dis (struct plant *array, int sp, struct plant *centroid, int ct) {

    float   sum = pow((array[sp].growth_pattern-centroid[ct].growth_pattern)*20,2);             // 0 - 4        *20 to scale 0-100
            sum += pow((array[sp].soil_type-centroid[ct].soil_type)*14,2);                      // 0 - 7        *14 to scale 0-100
            sum += pow((array[sp].min_temp-centroid[ct].min_temp)*2,2);                         // 0 - 50       *2 to scale 0-100
            sum += pow(array[sp].min_humidity-centroid[ct].min_humidity,2);                     // 0 - 100      no scaling need
            sum += pow((array[sp].min_light-centroid[ct].min_light)/100,2);                     // 0 - 10000    /100 to scale 0-100
            sum += pow((array[sp].max_temp-centroid[ct].max_temp)*2,2);                         // 0 - 50       *2 to scale 0-100
            sum += pow(array[sp].max_humidity-centroid[ct].max_humidity,2);                     // 0 - 100      no scaling need
            sum += pow((array[sp].max_light-centroid[ct].max_light)/100,2);                     // 0 - 10000    /100 to scale 0-100
    
            float distance = sqrt(sum);
    return distance;
}

