# name of the executable: todo_api_0, todo_api_1, todo_api_2,
#  todo_api_3, todo_api_4, todo_api_5
# CC: the compiler to be used
# CFLAGS: -Wall -Werror -Wextra -pedantic

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
FILEA = 0-api.c socket_server.c
FILEB = 1-api.c socket_server.c
FILEC = 2-api.c socket_server.c
FILED = 3-api.c socket_server.c
RM = rm -rf

todo_api_0: $(FILEA)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_1: $(FILEB)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_2: $(FILEC)
	$(CC) $(CFLAGS) $^ -o $@
todo_api_3: $(FILED)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *~ $(FILEA) $(FILEB) $(FILEC) $(FILED)
.PHONY: clean todo_api_0 todo_api_1 todo_api_2 todo_api_3
