# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 16:31:33 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/19 09:54:42 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean

NAME = ft_tail
SRCS = main.c print.c string.c
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
