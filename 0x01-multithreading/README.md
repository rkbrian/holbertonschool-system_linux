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

### 2. Blur portion of an image (10-blur_portion.c) (not working)
Write a method that blurs a portion of an image using a Gaussian Blur.
 - Prototype: void blur_portion(blur_portion_t const *portion);, where:
 - portion points to a data structure described in the project requirements
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 10-main.c 10-blur_portion.c -o 10-blur_portion

### 4. Thread logger v2 (20-tprintf.c)
Write a function that uses the printf family to print out a given formatted string.
This time, you will also have to use a mutex to avoid race conditions. As you know, a mutex needs to be initialized, and destroyed, but we don't want to have to do that ourselves in our main.c program. Please read about Constructors and Destructors with GCC and it should all make sense :).
 - Prototype: int tprintf(char const *format, ...);
 - The output must be preceded by the calling thread ID, as the following output shows.
 - Tip: You are allowed to use global variables - Don't forget to run Betty with the option --allow-global-variables
NOTE: We first compile with our first version of tprintf to show the consequence of the race condition.
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 20-main.c 1-tprintf.c -o 20-tprintf -pthread
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 20-main.c 20-tprintf.c -o 20-tprintf -pthread

### 5. Number to prime factors (21-prime_factors.c)
Write a function that factorizes a number into a list of prime factors.
 - Prototype: list_t *prime_factors(char const *s);, where
 - s is the string representation of the number to factorize.
 - This number will be positive and fit into an unsigned long
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 21-main.c 21-prime_factors.c list.c -o 21-prime_factors

### 6. Number to prime factors v2
The goal of this task is to reproduce the previous task, and to improve it using a thread pool. The tread pool will have for purpose to execute a list of tasks. For this task, you will have to write 3 functions (all in the same file):
 - Create task
 Prototype: task_t *create_task(task_entry_t entry, void *param);. This function must return a pointer to the created task structure
 - Destroy task
 Prototype: void destroy_task(task_t *task);.
 - Execute task list - Thread entry
 Prototype: void *exec_tasks(list_t const *tasks);.
 - - This function serves as a thread entry
 - - This function can safely return NULL as its return value will not be retrieved
 - - This function must go through the list of tasks and execute them, but there’s a challenge:
 - - - Multiple thread will be going through the list of tasks, and a task must only be executed once
 - - You must use tprintf to print when a task is started, and completed
