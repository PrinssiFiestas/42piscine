/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:26:31 by lfiestas          #+#    #+#             */
/*   Updated: 2024/07/31 17:20:57 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int x)
{
	char	buffer[16];
	int		buffer_length;

	buffer_length = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (x < 0)
	{
		write(1, "-", 1);
		x *= -1;
	}
	while (x != 0)
	{
		buffer[buffer_length++] = x % 10 + '0';
		x /= 10;
	}
	while (buffer_length > 0)
	{
		write(1, &buffer[buffer_length - 1], 1);
		--buffer_length;
	}
}
