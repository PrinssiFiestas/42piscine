/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:44:36 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 10:44:52 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	size_t	arg_length;

	i = 1;
	while (i < argc)
	{
		arg_length = 0;
		while (argv[i][arg_length] != '\0')
			++arg_length;
		write(1, argv[i], arg_length);
		write(1, "\n", 1);
		++i;
	}
}
