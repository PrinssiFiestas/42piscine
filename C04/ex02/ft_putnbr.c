/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:44:54 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/11 14:15:59 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

void	ft_putnbr(int nb)
{
	long long int	num;
	char			digits[16];
	unsigned int	digits_length;

	num = nb;
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	digits_length = 0;
	while (num != 0)
	{
		digits[digits_length++] = num % 10 + '0';
		num /= 10;
	}
	while (digits_length != 0)
		write(1, &digits[--digits_length], 1);
}
/*
int main(void)
{
    ft_putnbr(0);
    write(1, "\n", 1);
    ft_putnbr(-1);
    write(1, "\n", 1);
    ft_putnbr(-546);
    write(1, "\n", 1);
    ft_putnbr(453);
    write(1, "\n", 1);
    ft_putnbr(1);
    write(1, "\n", 1);
    ft_putnbr(INT_MAX);
    write(1, "\n", 1);
    ft_putnbr(INT_MIN);
    write(1, "\n", 1);
}*/
