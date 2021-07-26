#include "laps.h"

/**
 * race_state - keeps track of the num of laps made by some race cars.
 * @id: array of int representing the “identifier” of each car.
 * @size: size of the array.
 */
void race_state(int *id, size_t size)
{
	static car_laps *carnum;
	/* current: node pointer for printing laps */
	car_laps *current;
	size_t laps = 0;

	if (size > 0)
	{
		if (id)
		{
			for (; laps < size; laps++)
				add_lap(&carnum, id[laps]);
			printf("Race state:\n");
			if (carnum)
			{
				current = carnum;
				while (current != NULL)
				{
					printf("Car %d [%d laps]\n", current->car_number, current->lapkeeper);
					current = current->next;
				}
			}
		}
		else
			return;
	}
	else if (size == 0)
		free_struct(carnum);
}

/**
 * create_car - create a new car struct
 * @newcar_number: id number of the new car
 * Return: new car struct or null
 */
car_laps *create_car(int newcar_number)
{
	car_laps *newcar;

	newcar = malloc(sizeof(car_laps));
	if (newcar == NULL)
		return (NULL);
	newcar->car_number = newcar_number;
	newcar->lapkeeper = 0;
	newcar->next = NULL;
	printf("Car %d joined the race\n", newcar_number);
	return (newcar);
}

/**
 * add_lap - create a new car struct
 * @car: node of car info
 * @carnum: id number of the car
 * Return: new car struct or null
 */
car_laps *add_lap(car_laps **car, int carnum)
{
	car_laps *current = NULL, *newcar = NULL, *tmp = NULL;

	if (*car == NULL) /* everything starts here */
		return (*car = create_car(carnum));
	current = *car;
	while (current != NULL)
	{
		/* current car number exists in the lap-adding list*/
		if (current->car_number == carnum)
		{
			current->lapkeeper++;
			return (current);
		}
		/* no miscall in the logic before, means a new car is in */
		else if (current->car_number > carnum)
		{
			newcar = create_car(carnum);
			/* tmp node stores the new car, then sort the pointing */
			if (tmp == NULL)
				*car = newcar;
			else
				tmp->next = newcar;
			newcar->next = current;
			return (newcar);
		}
		tmp = current;
		current = current->next;
	}
	newcar = create_car(carnum);
	tmp->next = newcar;
	return (newcar);
}

/**
 * free_struct - function to free malloced struct
 * @da_list: linked list to be freed
 */
void free_struct(car_laps *da_list)
{
	car_laps *temp_node;

	if (da_list == NULL)
		return;
	while (da_list != NULL)
	{
		temp_node = da_list->next;
		free(da_list);
		da_list = temp_node;
	}
}
