#ifndef LAPS_H
#define LAPS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * prototypes for laps
 */

typedef struct car_info {
    int car_number;
    int lapkeeper;
    struct car_info *next;
} car_laps;

void race_state(int *id, size_t size);
car_laps *create_car(int newcar_number);
car_laps **add_lap(car_laps *car, int carnum);
void free_struct(car_laps *da_list);


#endif
