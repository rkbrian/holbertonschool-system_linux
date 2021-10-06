#ifndef CPYTHON_H
#define CPYTHON_H

#include <listobject.h>
#include <object.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);
void print_python_string(PyObject *p);
void print_python_int(PyObject *p);

#endif /* CPYTHON_H */
