#!/usr/bin/python3
"""
Find and rewrite an ongoing process in the heap, with
given pid, string to be searched, and replace string

Usage: read_write_heap.py pid search_string replace_string
- where pid is the pid of the running process
- and strings are ASCII
The script should look only in the heap of the process
Output: you can print whatever you think is interesting
On usage error, print an error message on stdout and exit
  with status code 1
"""
import sys


"""Checking inputs correctness"""
if len(sys.argv) < 4:
    raise TypeError("too few arguments")
    sys.exit(1)
elif len(sys.argv) > 4:
    raise TypeError("too many arguments")
    sys.exit(1)
try:
    pid = int(sys.argv[1])
    if pid <= 0:
        raise TypeError("{} is not a valid pid".format(sys.argv[1]))
        sys.exit(1)
except:
    raise TypeError("{} is not a valid pid".format(sys.argv[1]))
    sys.exit(1)

search_string = str(sys.argv[2])
replace_string = str(sys.argv[3])
map_file_str = "/proc/{}/maps".format(pid)
print("[*] maps: {}".format(map_file_str))
mem_file_str = "/proc/{}/mem".format(pid)
print("[*] mem: {}".format(mem_file_str))

"""Attempt to open map and access"""
try:
    map_file = open(map_file_str, mode='r')
except:
    raise IOError("can not open file {}".format(map_file_str))
    sys.exit(1)
for read_line in map_file:
    phrase = read_line.split(' ')
    memory_address = phrase[0]
    permissions = phrase[1]
    offset = phrase[2]
    inode = phrase[4]
    pathname = phrase[-1][:-1]
    if pathname == "[heap]":
        break
print("[*] Found [heap]:")
print("\tpathname = {}".format(pathname))
print("\taddresses = {}".format(memory_address))
print("\tpermissions = {}".format(permissions))
print("\toffset = {}".format(offset))
print("\tinode = {}".format(inode))
if permissions[0] != 'r' or permissions[1] != 'w':
    print("{} does not have read/write permission".format(pathname))
    map_file.close()
    exit(1)

"""Check format correctness and address ranges in hexadecimal"""
addresses = memory_address.split("-")
if len(addresses) != 2:
    print("wrong address format")
    map_file.close()
    exit(1)
try:
    head_addr = int(addresses[0])
    tail_addr = int(addresses[1])
    print("[*] Addr start [{}] | end [{}]".format(head_addr, tail_addr))
except:
    raise ValueError("wrong address value")
    map_file.close()
    exit(1)

"""Attempt to open memory and access"""
try:
    mem_file = open(mem_file_str, mode='rb+')
except:
    raise IOError("can not open file {}".format(mem_file_str))
    map_file.close()
    exit(1)

"""Seek() method to find the line in heap and read heap, search string"""
mem_file.seek(head_addr)
heap = mem_file.read(tail_addr - head_addr)
try:
    h_index = heap.index(bytes(search_string, "ASCII"))
    print("[*] Found '{}' at {}".format(search_string, h_index))
except:
    raise Exception("can not find {}".format(search_string))
    map_file.close()
    mem_file.close()
    exit(1)

"""Replace the string"""
if len(replace_string) > h_index:
    raise ValueError("replace string is too long")
    map_file.close()
    mem_file.close()
    exit(1)
str_position = head_addr + h_index
mem_file.seek(str_position)
print("[*] Writing '{}' at {}".format(replace_string, str_position))
mem_file.write(bytes(replace_string + '\0', "ASCII"))
map_file.close()
mem_file.close()
