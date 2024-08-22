# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 15:20:05 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/15 11:19:20 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

all: do-op

do-op: $(OBJS)
	cc $^ -o $@

$(OBJS): %.o : %.c
	cc -c -Wall -Wextra -Werror $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f do-op $(OBJS)

re: fclean
re: all
