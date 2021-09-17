#include "libasm.h"

/**
 * puti_base - I just feel like I need to do the documentation thing
 */
unsigned int puti_base(int n, const char *base)
{
	int digit;
	int power = 0, base_power = 1;
	int num = n, base_num = strlen(base), tmp;
	int i, j, ret_byte = 0;

	if (n == 0)
	{
		putchar(base[0]), ret_byte++;
		return (ret_byte);
	}
	if (n < 0)
		putchar('-'), num = num * (-1);
	tmp = num;
	while (tmp >= 1)
	{
		tmp = tmp / base_num, power++;
	}
	for (i = power - 1; i >= 0; i--)
	{
		j = 0;
		while (j < i)
		{
			base_power = base_power * base_num; /*for b16, 16^4*/
			j++;
		}
		digit = num / base_power; /*98765/16^4=1*/
		putchar(base[digit]);
		num = num % base_power;/*98765 - 1*16^4=33229 for next num!*/
		base_power = 1;/*reset*/
		ret_byte++;
	}
	return (ret_byte);
}
