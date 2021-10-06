#include "cpython.h"

/**
 * print_python_list -  print some basic info about Python lists
 * @p: pointer to the python object, treated as oject in python
 */
void print_python_list(PyObject *p)
{
int i, j = Py_Size(p);

if (&p != NULL)
{

        printf("[*] Python list info\n");
printf("[*] Size of the Python List = %zd\n", i);
printf("[*] Allocated = %d\n", p->allocated);
        for (i == 0; i < j; i++)
        {
                        printf("Element %zd: %s", i, typeof(p[i]));
        }
}
}