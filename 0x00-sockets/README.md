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

### 0 - Listen:
 Terminal 1: **./0-server**\
 Terminal 2: lsof -i :12345; killall 0-server

### 1 - Accept:
 Termianl 1: **./1-server**\
 Terminal 2: ./1-client localhost 12345

### 2 - Client
 Ternimal 1: ./2-server\
 Termianl 2: **./2-client** localhost 12345

### 3 - Roger
 Terminal 1: **./3-server**\
 Terminal 2: ./3-client localhost 12345 'my message'
