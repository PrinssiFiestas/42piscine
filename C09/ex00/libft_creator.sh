# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 08:36:25 by lfiestas          #+#    #+#              #
#    Updated: 2024/08/14 08:36:47 by lfiestas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc -c -Wall -Wextra -Werror ft_putchar.c
cc -c -Wall -Wextra -Werror ft_swap.c
cc -c -Wall -Wextra -Werror ft_putstr.c
cc -c -Wall -Wextra -Werror ft_strlen.c
cc -c -Wall -Wextra -Werror ft_strcmp.c
ar -crs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
