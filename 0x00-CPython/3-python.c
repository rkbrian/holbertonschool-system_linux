#include "cpython.h"

/**
 * print_python_list -  print some basic info about Python lists
 * @p: pointer to the python object, treated as object in python
 */
void print_python_list(PyObject *p)
{
	PyListObject *pl;
	Py_ssize_t i, j;

	pl = (PyListObject *)p;
	if (pl != NULL && PyList_Check(pl))
	{
		j = PyList_GET_SIZE(p);
		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %zd\n", j);
		printf("[*] Allocated = %zd\n", pl->allocated);
		for (i = 0; i < j; i++)
		{
			printf("Element %zd: ", i);
			printf("%s\n", pl->ob_item[i]->ob_type->tp_name);
			if (pl->ob_item[i]->ob_type->tp_name[0] == 'l')
			{
				print_python_bytes(NULL);
				print_python_float(NULL);
			}
			else
			{
				print_python_bytes(pl->ob_item[i]);
				print_python_float(pl->ob_item[i]);
			}
		}
	}
	else
	{
		printf("[*] Python list info\n");
		printf("  [ERROR] Invalid List Object\n");
	}
}

/**
 * print_python_bytes - print some info about Python bytes objects
 * @p: pointer to the python object, treated as object in python
 */
void print_python_bytes(PyObject *p)
{
	PyBytesObject *pb;
	Py_ssize_t i, j;

	if (p != NULL && PyBytes_Check(p))
	{
		pb = (PyBytesObject *)p;
		printf("[.] bytes object info\n");
		for (i = 0; i < pb->ob_base.ob_size; i++)
		{
		}
		printf("  size: %zd\n", i);
		printf("  trying string: %s\n", pb->ob_sval), i++;
		if (i > 10)
			i = 10;
		printf("  first %zd bytes:", i);
		for (j = 0; j < i; j++)
			printf(" %02x", pb->ob_sval[j] & 0xff);
		printf("\n");
	}
	else if (p == NULL || PyList_Check(p))
	{
		printf("[.] bytes object info\n");
		printf("  [ERROR] Invalid Bytes Object\n");
	}
}

/**
 * print_python_float - print some info about Python float objects
 * @p: pointer to the python object, treated as object in python
 */
void print_python_float(PyObject *p)
{
	PyFloatObject *pf;
	long int a;

	if (p != NULL && PyFloat_Check(p))
	{
		pf = (PyFloatObject *)p;
		printf("[.] float object info\n  value: ");
		a = pf->ob_fval;
		if (a == pf->ob_fval)
			printf("%.1f", pf->ob_fval);
		else if (a >= INT_MAX || a <= INT_MIN)
			printf("%ld.0", a);
		else
			printf("%.16g", pf->ob_fval);
		printf("\n");
	}
	else if (p == NULL || PyList_Check(p))
	{
		printf("[.] float object info\n");
		printf("  [ERROR] Invalid Float Object\n");
	}
}
