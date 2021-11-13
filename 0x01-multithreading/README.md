# 0x01. Multithreading
## General
 - What is a thread
 - What are the differences between a thread and a process
 - What is the difference between Concurrency and Parallelism
 - How to create a thread
 - How to properly exit a thread
 - How to handle mutual execution
 - What is a deadlock
 - What is a race condition

### 0. Thread entry point (0-thread_entry.c)
Write a function that will serve as the entry point to a new thread.
 - Prototype: void *thread_entry(void *arg);, where:
 - arg holds the address of a string that must be printed and followed by a new line.
 - Make sure to respect the order
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 0-main.c 0-thread_entry.c -o 0-thread_entry -pthread

### 1. Thread Logger (1-tprintf.c)
Write a function that uses the printf family to print out a given formatted string.
 - Prototype: int tprintf(char const *format, ...);
 - The output must be preceded by the calling thread ID.
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 1-main.c 1-tprintf.c -o 1-tprintf -pthread

### 2. Blur portion of an image (10-blur_portion.c)
Write a method that blurs a portion of an image using a Gaussian Blur.
 - Prototype: void blur_portion(blur_portion_t const *portion);, where:
 - portion points to a data structure described in the project requirements
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 10-main.c 10-blur_portion.c -o 10-blur_portion

### 5. Number to prime factors (21-prime_factors.c)
Write a function that factorizes a number into a list of prime factors.
 - Prototype: list_t *prime_factors(char const *s);, where
 - s is the string representation of the number to factorize.
 - This number will be positive and fit into an unsigned long
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 21-main.c 21-prime_factors.c list.c -o 21-prime_factors
