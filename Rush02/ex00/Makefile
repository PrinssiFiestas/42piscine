# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 16:53:52 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/18 12:41:02 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = clang
SRCS = $(wildcard *.c) # TODO fix this
OBJS = $(patsubst %.c,%.o,$(SRCS))
CFLAGS = -ggdb3 -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined

all: rush-02

rush-02: $(OBJS)
	clang $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f rush-02 $(OBJS)

re: fclean
re: all
