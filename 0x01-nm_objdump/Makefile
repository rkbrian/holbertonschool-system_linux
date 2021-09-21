# nameof the executable: hnm, hobjdump
# CC: the compiler to be used
# CFLAGS: -Wall -Werror -Wextra -pedantic
# rules: all

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
FILEA = 0-hnm.c
FILEB = 1-hobjdump.c
RM = rm -rf

hnm: $(FILEA)
	$(CC) $(CFLAGS) $^ -o $@
hobjdump:
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *~ $(FILEA) $(FILEB)
.PHONY: clean hnm hobjdump
