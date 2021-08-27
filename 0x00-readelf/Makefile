# nameof the executable: 0-hreadelf, 1-hreadelf, 2-hreadelf
# CC: the compiler to be used
# CFLAGS: -Wall -Werror -Wextra -pedantic
# rules: all

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
FILEA = 0-hreadelf.c print_set_1.c print_set_2.c
FILEB = 1-hreadelf.c sec_print_1.c sec_print_2.c
FILEC = 2-hreadelf.c pro_print_1.c pro_print_2.c
RM = rm -rf

0-hreadelf: $(FILEA)
	$(CC) $(CFLAGS) $^ -o $@
1-hreadelf: $(FILEB)
	$(CC) $(CFLAGS) $^ -o $@
2-hreadelf: $(FILEC)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) *~ $(FILEA) $(FILEB) $(FILEC)
.PHONY: clean 0-hreadelf 1-hreadelf 2-hreadelf
