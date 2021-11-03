# 0x00. C - Strace
## General
 - What is strace, and what is its purpose
 - What is ptrace, and what possibilties it offers
 - What are the differences between PTRACE_SINGLESTEP and PTRACE_SYSCALL
 - How to read from and/or write to the memory of a process being traced

### 0. Step 0 - Syscall number
Write a program that executes and traces a given command.
 - Usage: ./strace_0 command [args...]
 - Each time a syscall is intercepted, you must print its number, followed by a new line
 - You don't have to handle the PATH: command will be a full path to a binary (Ex: /bin/ls and not ls)
 - Your Makefile must implement a rule strace_0

### 1. Step 1 - Syscall name
Write a program that executes and traces a given command.
 - Usage: ./strace_1 command [args...]
 - Each time a syscall is intercepted, you must print its name, followed by a new line
 - You don't have to handle the PATH: command will be a full path to a binary (Ex: /bin/ls and not ls)
 - Your Makefile must implement a rule strace_1

### 2. Step 2 - Return value
Write a program that executes and traces a given command.
 - Usage: ./strace_2 command [args...]
 - Each time a syscall is intercepted, you must print its name and its return value in hexadecimal, followed by a new line (see example)
 - You don't have to handle the PATH: command will be a full path to a binary (Ex: /bin/ls and not ls)
 - Your Makefile must implement a rule strace_2
 - NOTES: It is impossible to retrieve the last system call return value, simply because it doesn't return. So, just print a ? like strace does.

### 3. Step 3 - Raw parameters
Write a program that executes and traces a given command...
