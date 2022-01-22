# Memo
# Theoretically every compilation here needs to free allocation,
# but the most given test files didn't include the freeing.
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
PTREE = rb_tree_print.c
NNODE = 0-rb_tree_node.c

rb_tree_node: $(PTREE) $(NNODE) 0-main.c
	$(CC) $(CFLAGS) $^ -o $@
	