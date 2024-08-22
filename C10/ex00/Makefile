# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 15:20:32 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/19 08:28:39 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean

NAME = ft_display_file

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
