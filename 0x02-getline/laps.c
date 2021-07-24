#include "laps.h"

/**
 * race_state - keeps track of the num of laps made by some race cars.
 * @id: array of int representing the “identifier” of each car.
 * @size: size of the array.
 */
void race_state(int *id, size_t size)
{
    static car_laps **unknown_car = NULL;
    size_t lapkeeper = 0;

    if (size > 0)
    {
        if (id != NULL)
        {
            for (; lapkeeper < size; lapkeeper++)
                create_car(id);
        }
        else
    }
    printf("Race state:\n");
    while (!= NULL)
    {
        ;
        printf("Car %d [%d laps]")
    }
    if (size == 0)
        free(carnum);
    
    ;
}

/**
 * create_car - create a new car struct
 * @car_number: id number of the new car
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
    newcar = newcar->next;
    printf("Car %d joined the race\n", newcar_number);
    return (newcar);
}

/**
 * add_lap - create a new car struct
 * @car_number: id number of the new car
 * Return: new car struct or null
 */
car_laps *add_lap(car_laps **runcar, int runcar_number)
{
    car_laps *new_lap;

    if (*runcar = NULL)
        return create_car(runcar_number);
    while (new_lap != NULL)
    {
        new_lap->car_number = runcar_number;
        new_lap->lapkeeper++;
        new_lap = new_lap->next;
    }

    printf("Car %d joined the race\n", id[size]);
}
