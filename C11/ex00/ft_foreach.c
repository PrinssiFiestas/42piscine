/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:55:59 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/13 19:30:17 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		++i;
	}
}
/*
#include <unistd.h>
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
	write(1, "\n", 1);
}

int main(void)
{
	int arr[] = { 3, 75, -12, 35 };
	ft_foreach(arr, sizeof arr / sizeof*arr, ft_putnbr);
	ft_foreach(arr, 0, ft_putnbr);
}*/
