/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:44:09 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/02 11:34:57 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	buf[4];

	buf[0] = '\\';
	while (*str != '\0')
	{
		if (*str < 32 || *str == 127)
		{
			if (*str / 16 < 10)
				buf[1] = *str / 16 + '0';
			else
				buf[1] = *str / 16 - 10 + 'a';
			if (*str % 16 < 10)
				buf[2] = *str % 16 + '0';
			else
				buf[2] = *str % 16 - 10 + 'a';
			write(1, buf, 3);
		}
		else
		{
			write(1, str, 1);
		}
		++str;
	}
}
