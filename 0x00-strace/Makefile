# name of the executable: strace_0, strace_1, strace_2, strace_3
# rules: all
# CC: the compiler to be used
# CFLAGS: -Wall -Werror -Wextra -pedantic

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
FILEA = 0-main.c
FILEB = 1-main.c
FILEC = 2-main.c
FILED = 3-main.c
RM = rm -rf

strace_0: $(FILEA)
	$(CC) $(CFLAGS) $^ -o $@
strace_1: $(FILEB)
	$(CC) $(CFLAGS) $^ -o $@
strace_2: $(FILEC)
	$(CC) $(CFLAGS) $^ -o $@
strace_3: $(FILED)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *~ $(FILEA) $(FILEB) $(FILEC) $(FILED)
.PHONY: clean strace_0 strace_1 strace_2 strace_3
