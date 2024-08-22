SRCS = ex00/ft_create_elem.c ex01/ft_list_push_front.c ex02/ft_list_size.c
SRCS += ex03/ft_list_last.c ex04/ft_list_push_back.c ex05/ft_list_push_strs.c
SRCS += ex06/ft_list_clear.c ex07/ft_list_at.c ex08/ft_list_reverse.c
SRCS += ex09/ft_list_foreach.c ex10/ft_list_foreach_if.c ex11/ft_list_find.c
SRCS += ex12/ft_list_remove_if.c ex13/ft_list_merge.c ex14/ft_list_sort.c
SRCS += tests.c

all: test

test:
	cc -ggdb3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -Wall -Wextra -Werror $(SRCS)

