#include "cpython.h"

/**
 * print_python_list -  print some basic info about Python lists
 * @p: pointer to the python object, treated as object in python
 */
void print_python_int(PyObject *p)
{
	PyLongObject *pl;
	unsigned long int i;

	if (p != NULL && PyLong_Check(p))
	{
		pl = (PyLongObject *)p;
                if (pl->ob_digit <= (2 << PyLong_SHIFT) || )
			i = pl->ob_digit, printf("%lu\n", i);
		else
		{
			printf("C unsigned long int overflow\n");
		}
	}
	else
		printf("Invalid Int Object\n");
}