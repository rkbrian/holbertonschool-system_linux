# 0x00. Sockets

## General
 - What is a socket and how it is represented on a Linux/UNIX system
 - What are the different types of sockets
 - What are the different socket domains
 - How to create a socket
 - How to bind a socket to an address/port
 - How to listen and accept incoming traffic
 - How to connect to a remote application
 - What is the the HTTP protocol
 - How to create a simple HTTP server

## Projects
Working but flawed: :radioactive:\
Ongoing: :thinking:
### 0 - Listen:
 Compile: gcc -Wall -Wextra -Werror -pedantic -o 0-server 0-server.c\
 Terminal 1: **./0-server**\
 Terminal 2: lsof -i :12345; killall 0-server

### 1 - Accept:
 Compile: gcc -Wall -Wextra -Werror -pedantic -o 1-server 1-server.c\
 Termianl 1: **./1-server**\
 Terminal 2: ./1-client localhost 12345

### 2 - Client
 Compile: gcc -Wall -Wextra -Werror -pedantic -o 2-client 2-client.c\
 Ternimal 1: ./2-server\
 Termianl 2: **./2-client** localhost 12345

### 3 - Roger
 Compile: gcc -Wall -Wextra -Werror -pedantic -o 3-server 3-server.c\
 Terminal 1: **./3-server**\
 Terminal 2: ./3-client localhost 12345 'my message'

### 4 - REST API - The Request
 Terminal 1: make todo_api_0; **./todo_api_0**\
 Terminal 2: curl -D - 'http://localhost:8080/test' 2> /dev/null | cat -e; curl -D - -X POST 'http://localhost:8080/holberton' 2> /dev/null | cat -e

### 5 - REST API - Queries
 Terminal 1: make todo_api_1; **./todo_api_1**\
 Terminal 2: curl -D - 'http://localhost:8080/test?value1=holberton&value2=school' 2> /dev/null | cat -e

### 6 - REST API - Headers
 Terminal 1: make todo_api_2; **./todo_api_2**\
 Termianl 2: curl -D - 'http://localhost:8080/test' 2> /dev/null | cat -e

### 7 - REST API - Body parameters
 Terminal 1: make todo_api_3; **./todo_api_3**\
 Terminal 2: curl -D - -X POST 'http://localhost:8080/test' -d 'value1=holberton&value2=school' 2> /dev/null | cat -e

### 8 - REST API - Create TODO
:thinking:\
 Terminal 1: make todo_api_4; **./todo_api_4**\
 Terminal 2: curl -D - -X POST 'http://localhost:8080/todos' -d 'title=Dishes&description=Not_really_urgent' 2> /dev/null | cat -e
 Terminal 2: curl -D - -X POST 'http://localhost:8080/todos' -d 'title=Homework' 2> /dev/null | cat -e
 Terminal 2: curl -D - -X POST 'http://localhost:8080/holberton' -d 'title=Dishes&description=Not_really_urgent' 2> /dev/null | cat -e
 Terminal 2: curl -D - 'http://localhost:8080/todos' 2> /dev/null | cat -e
 