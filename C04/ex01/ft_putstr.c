/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:44:25 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/08 16:03:20 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length] != '\0')
		++length;
	write(1, str, length);
}
/*
int main(void)
{
    ft_putstr("");
    ft_putstr("blah\n");
}*/
