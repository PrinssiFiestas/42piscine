/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:22:58 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/01 08:35:57 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_comb(int n, char digit, char digits[], int digits_length)
{
	char	i;

	if (n == 0)
	{
		write(1, digits, digits_length);
		if (digits[0] <= '9' - digits_length)
			write(1, ", ", 2);
		return ;
	}
	i = digit;
	while (i <= '9')
	{
		digits[digits_length - n] = i;
		print_comb(n - 1, i + 1, digits, digits_length);
		++i;
	}
}

void	ft_print_combn(int n)
{
	char	digits[12];

	print_comb(n, '0', digits, n);
}
