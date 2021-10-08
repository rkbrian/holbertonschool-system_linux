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
		j = PyList_Size(p);
		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %zd\n", j);
		printf("[*] Allocated = %zd\n", pl->allocated);
		for (i = 0; i < j; i++)
		{
			printf("Element %zd: ", i);
			printf("%s\n", pl->ob_item[i]->ob_type->tp_name);
			print_python_bytes(pl->ob_item[i]);
		}
	}
}

/**
 * print_python_bytes -  print some info about Python lists and bytes objects
 * @p: pointer to the python object, treated as object in python
 */
void print_python_bytes(PyObject *p)
{
	PyBytesObject *pb;
	Py_ssize_t i, j;

	pb = (PyBytesObject *)p;
	if (pb != NULL && PyBytes_Check(pb))
	{
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
}
