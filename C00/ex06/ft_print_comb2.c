/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:58:09 by lfiestas          #+#    #+#             */
/*   Updated: 2024/07/31 17:13:42 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	i;
	char	j;
	char	buffer[16];

	buffer[2] = ' ';
	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			buffer[0] = i / 10 + '0';
			buffer[1] = i % 10 + '0';
			buffer[3] = j / 10 + '0';
			buffer[4] = j % 10 + '0';
			write(1, buffer, 5);
			if (i != 98 || j != 99)
				write(1, ", ", 2);
			++j;
		}
		++i;
	}
}
