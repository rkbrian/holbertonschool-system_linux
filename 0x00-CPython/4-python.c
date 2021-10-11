#include "cpython.h"

/**
 * print_python_string - print Python strings
 * @p: pointer to the python object, treated as object in python
 */
void print_python_string(PyObject *p)
{
	PyStringObject *ps;
	Py_ssize_t i, j;

	if (p != NULL && PyString_Check(p))
	{
		ps = (PyStringObject *)p;
		printf("[.] string object info\n");
		printf("  type: compact ");
		if (ps->ob_sval)
			printf("ascii\n");
		else
			printf("unicode object\n");
		j = PyString_Size(p);
		printf("  length: %zd\n  value: ", j);
		wprintf(L"%ls\n", ps->ob_ob_sval); /* maybe? */
		printf("\n");
	}
	else
	{
		printf("[.] string object info\n");
		printf("  [ERROR] Invalid String Object\n");
	}
}
