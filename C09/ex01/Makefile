# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 16:53:52 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/15 14:04:44 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c
SRCS += srcs/ft_strcmp.c
OBJS = $(patsubst srcs/%.c,srcs/%.o,$(SRCS))
CFLAGS = -Wall -Wextra -Werror -I includes

all: libft.a

libft.a: $(OBJS)
	ar -crs $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f libft.a $(OBJS)

re: fclean
re: all
