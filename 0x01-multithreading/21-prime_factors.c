#include "multithreading.h"

/**
 * prime_factors - factorize a number into a list of prime factors.
 * @s: string representation of the number to factorize.
 * Return: list of prime factors
 */
list_t *prime_factors(char const *s)
{
	unsigned long factory = 2, num = strtoul(s, NULL, 10);
	unsigned long *factptr = NULL;
	list_t *primely = NULL;

	primely = malloc(sizeof(list_t));
	if (!primely)
		return (NULL);
	list_init(primely);
	while (num > factory * factory)
	{
		while (num % factory == 0)
		{
			factptr = malloc(sizeof(unsigned long));
			*factptr = factory, list_add(primely, (void *)factptr);
			num = num / factory;
		}
		factory++;
		if (factory > 3)
			factory++;
	}
	if (num >= 2)
	{
		factptr = malloc(sizeof(unsigned long));
		*factptr = num, list_add(primely, (void *)factptr);
	}
	return (primely);
}
