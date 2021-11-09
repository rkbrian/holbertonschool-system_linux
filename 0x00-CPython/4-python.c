#include "cpython.h"

/**
 * print_python_string - print Python strings
 * @p: pointer to the python object, treated as object in python
 */
void print_python_string(PyObject *p)
{
	Py_ssize_t j;

	if (p != NULL && PyUnicode_Check(p))
	{
		printf("[.] string object info\n");
		printf("  type: ");
		if (PyUnicode_IS_COMPACT_ASCII(p))
			printf("compact ascii\n");
		else if (PyUnicode_IS_COMPACT(p))
			printf("compact unicode object\n");
		else if (PyUnicode_KIND(p) == PyUnicode_WCHAR_KIND)
			printf("legacy string, not ready");
		else if (!PyUnicode_IS_COMPACT(p))
			printf("legacy string, ready");
		j = ((PyASCIIObject *)p)->length;
		printf("  length: %zd\n  value: ", j);
		printf("%ls\n", (PyUnicode_AsWideCharString(p, NULL)));
	}
	else
	{
		printf("[.] string object info\n");
		printf("  [ERROR] Invalid String Object\n");
	}
}
