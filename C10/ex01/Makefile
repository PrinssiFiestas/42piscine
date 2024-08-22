# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 15:20:39 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/19 13:27:43 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_cat

all: $(NAME)

$(NAME): main.o
	cc $? -o $@

main.o: main.c
	cc -c -Wall -Wextra -Werror $? -o $@

clean:
	rm -f main.o

fclean:
	rm -f main.o $(NAME)

re: fclean all
