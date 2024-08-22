# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 15:20:05 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/19 08:32:43 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean

NAME = ft_hexdump
SRCS = ft_hexdump.c ft_hexdump2.c
OBJS = $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	cc $^ -o $@

$(OBJS): %.o : %.c
	cc -c -Wall -Wextra -Werror $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all
