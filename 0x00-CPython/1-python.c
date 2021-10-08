#include "cpython.h"

/**
 * print_python_list -  print some basic info about Python lists
 * @p: pointer to the python object, treated as oject in python
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i, j = PyList_Size(p);

	if (p != NULL && PyList_Check(p))
	{
		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %zd\n", j);
		printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);
		for (i = 0; i < j; i++)
		{
			printf("Element %zd: ", i);
			printf("%s\n", ((PyListObject *)p)->ob_item[i]->ob_type->tp_name);
		}
	}
}
