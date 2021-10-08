# 0x00. CPython
CPython is the reference implementation of the Python programming language. Written in C, CPython is the default and most widely used implementation of the language.

### 0. Lists big O
Write the big O notations for the following lists operations (one per line, in this exact order):
- L1 - Assigning. Example: holberton[98] = 402
- L2 - Appending. Example: holberton.append(98)
- L3 - Concatenating a list of n elements. Example: holberton + [98, 402]
- L4 - Inserting an item at a given position. Example: holberton.insert(98, 402)
- L5 - Removing an element. Example: holberton.remove(98)
- L6 - Removing and returning the last item in the list. Example: holberton.pop()
- L7 - Poping an element at a given position. Example: holberton.pop(98)
- L8 - Clearing a list. Example: holberton.clear()
- L9 - Counting the list. Example: holberton.count()
- L10 - Sorting the list. Example: holberton.sort()
- L11 - Reversing the list. Example: holberton.reverse()
- L12 - Deleting the list. Example: del holberton

### 1. CPython #0: Python lists
Create a C function that prints some basic info about Python lists.
Compile command: gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,PyList -o libPyList.so -fPIC -I/usr/include/python3.4 1-python.c
Run process: python3 1-tests.py

### 2. CPython #1: PyBytesObject
Create two C functions that print some basic info about Python lists and Python bytes objects.
Compile command: gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,libPython.so -o libPython.so -fPIC -I/usr/include/python3.4 2-python.c
Run process: python3 2-tests.py

### 3. CPython #2: PyFloatObject
Create three C functions that print some basic info about Python lists, Python bytes an Python float objects.
Compile command: gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,libPython.so -o libPython.so -fPIC -I/usr/include/python3.4 3-python.c
Run process: python3 3-tests.py

### 4. CPython #3: Python Strings
Create a function that prints Python strings.
Compile command

### 5. CPython Integers
Create a C function that prints Python integers.
Compile command

### 6. CPython Integers
Create a C function that prints Python integers.
Compile command
