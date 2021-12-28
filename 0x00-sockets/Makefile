# name of the executable: todo_api_0, todo_api_1, todo_api_2,
#  todo_api_3, todo_api_4, todo_api_5
# CC: the compiler to be used
# CFLAGS: -Wall -Werror -Wextra -pedantic
# SERV: socket server file, creates a socket and do setsockopt, bind, listen

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SERV = socket_server.c
FILEA = 0-api.c
FILEB = 1-api.c
FILEC = 2-api.c
FILED = 3-api.c
FILEE = 4-api.c
FILEF = 5-api.c
RM = rm -rf

todo_api_0: $(FILEA) $(SERV)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_1: $(FILEB) $(SERV)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_2: $(FILEC) $(SERV)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_3: $(FILED) $(SERV)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_4: $(FILEE) $(SERV)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_5: $(FILEF) $(SERV)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *~ $(FILEA) $(FILEB) $(FILEC) $(FILED) $(SERV)
.PHONY: clean todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5
