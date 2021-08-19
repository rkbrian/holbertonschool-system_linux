# 0x01. Python - /proc filesystem
## General
What is the /proc filesystem
What is the /proc/maps file
What is the /proc/mem file
What is the link between those two files
How does the virtual memory map into the RAM

## 0. Hack the VM
Write a script that finds a string in the heap of a running process, and replaces it.

Usage: read_write_heap.py pid search_string replace_string
where pid is the pid of the running process
and strings are ASCII
The script should look only in the heap of the process
Output: you can print whatever you think is interesting
On usage error, print an error message on stdout and exit with status code 1

## 1. Blog Post
https://docs.google.com/document/d/1qOUckG_7rBiNT2cWNPdwitUfzLPIWvhG/edit?usp=sharing&ouid=110860371606464415133&rtpof=true&sd=true
