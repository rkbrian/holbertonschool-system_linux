#!/usr/bin/python3
"""Module for unction to rewrite an ongoing process"""
import sys


"""Checking inputs correctness"""
if len(sys.argv) < 3:
    raise TypeError("too few arguments")
elif len(sys.argv) > 3:
    raise TypeError("too many arguments")

try:
    pid = int(sys.argv[1])
except:
    raise ValueError

search_string = str(sys.argv[2])
replace_string = str(sys.argv[3])
map_file_str = "/proc/{}/maps".format(pid)
print("[*] maps: {}".format(map_file_str))
mem_file_str = "/proc/{}/mem".format(pid)
print("[*] mem: {}".format(mem_file_str))

"""Attempt to open map and access"""
try:
    with open(map_file_str, mode="r") as map_file
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

"""Check format correctness and address ranges in hexadecimal"""
addresses = memory_address.split("-")
if len(address) != 2:
    print("wrong address format")
    map_file.close()
    exit(1)
try:
    head_addr = int(addresses[0], 16)
    tail_addr = int(addresses[1], 16)
except:
    raise ValueError("wrong address value")

"""Attempt to open memory and access"""
try:
    with open(mem_file_str, mode="rb+") as mem_file
except:
    raise IOError("can not open file {}".format(mem_file_str))
    map_file.close()
    exit(1)

"""Seek method to find the line in heap and read heap"""
mem_file.seek(head_addr)
heap = mem_file.read(tail_addr - head_addr)

"""Search string"""





print("[*] Found [heap]:")
print("        pathname = {}".format(pathname))
print("        addresses = {}".format(memory_address))
print("        permissions = {}".format(permissions))
print("        offset = {}".format(offset))
print("        inode = {}".format(inode))

"""Write the string"""
mem_file.seek()
