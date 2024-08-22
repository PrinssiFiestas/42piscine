/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:45:57 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 10:50:25 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	size_t	i;
	size_t	arg_length;

	i = argc - 1;
	while (i > 0)
	{
		arg_length = 0;
		while (argv[i][arg_length] != '\0')
			++arg_length;
		write(1, argv[i], arg_length);
		write(1, "\n", 1);
		--i;
	}
}
