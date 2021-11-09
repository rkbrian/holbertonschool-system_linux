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
 - Make sure to respect the order:
