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

### 0. Thread entry point
Write a function that will serve as the entry point to a new thread.
 - Prototype: void *thread_entry(void *arg);, where:
 - arg holds the address of a string that must be printed and followed by a new line.
 - Make sure to respect the order
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 0-main.c 0-thread_entry.c -o 0-thread_entry -pthread

### 1. Thread Logger
Write a function that uses the printf family to print out a given formatted string.
 - Prototype: int tprintf(char const *format, ...);
 - The output must be preceded by the calling thread ID.
compile command: gcc -Wall -Wextra -Werror -pedantic -g3 1-main.c 1-tprintf.c -o 1-tprintf -pthread
