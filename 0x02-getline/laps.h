#ifndef LAPS_H
#define LAPS_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct car_info - struct with racing car info, integer contents only
 * @car_number: race car number
 * @lapkeeper: number to keep total laps of the car in the race
 * @next: linked list pointer to the next node
 */
typedef struct car_info
{
	int car_number;
	int lapkeeper;
	struct car_info *next;
} car_laps;


void race_state(int *id, size_t size);
car_laps *create_car(int newcar_number);
car_laps *add_lap(car_laps **car, int carnum);
void free_struct(car_laps *da_list);

#endif
