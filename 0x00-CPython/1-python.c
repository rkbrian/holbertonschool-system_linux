#include "cpython.h"

/**
 * print_python_list -  print some basic info about Python lists
 * @p: pointer to the python object, treated as oject in python
 */
void print_python_list(PyObject *p)
{
	/*PyTypeObject *plist = p->ob_type;*/
	/* initialize PyList_Type instance */
	static PyTypeObject PyList_Type = {
		PyVarObject_HEAD_INIT(&PyList_Type, 0)
		"list",
		sizeof(PyListObject),
		0, /* tp_itemsize */
		0, /* tp_dealloc */
		0, /* tp_print */
		0, /* tp_getattr */
		0, /* tp_setattr */
		0, /* tp_as_async */
		0, /* tp_repr */
		0, /* tp_as_number */
		0, /* tp_as_sequence */
		0, /* tp_as_mapping */
		0, /* tp_hash  */
		0, /* tp_call */
		0, /* tp_str */
		0, /* tp_getattro */
		0, /* tp_setattro */
		0, /* tp_as_buffer */
		Py_TPFLAGS_DEFAULT, /* tp_flags */
		"List objects", /* tp_doc */
	};
	Py_ssize_t i, j = PyList_Size(PyList_Type->ob_item);

	if (p != NULL) /* && Py_Is_TYPE(p, PyList_type) != 0)*/
	{

		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %zd\n", j);
		printf("[*] Allocated = %zd\n", PyList_Type->allocated);
		for (i = 0; i < j; i++)
		{
			printf("Element %zd: ", i);
			/*if (p->ob_type)*/
		/*printf("str\n");*/
		/*printf("int\n");*/
		}
	}
}
