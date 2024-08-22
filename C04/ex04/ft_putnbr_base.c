/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:50:20 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 09:46:12 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	validate_base(char *base)
{
	unsigned int	base_length;
	unsigned int	i;

	base_length = 0;
	while (base[base_length] != 0)
	{
		if (base[base_length] == '+' || base[base_length] == '-')
			return ((unsigned int)-1);
		i = 0;
		while (i < base_length)
		{
			if (base[base_length] == base[i])
				return ((unsigned int)-1);
			++i;
		}
		++base_length;
	}
	return (base_length);
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char			digits[32];
	unsigned int	digits_length;
	int				positive_nbr;
	unsigned int	base_length;

	base_length = validate_base(base);
	if (base[0] == '\0' || base[1] == '\0' || base_length == (unsigned int)-1)
		return ;
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	positive_nbr = abs(nbr);
	digits_length = 0;
	while (positive_nbr != 0)
	{
		digits[digits_length++] = base[positive_nbr % base_length];
		positive_nbr /= base_length;
	}
	if (nbr < 0)
		write(1, "-", 1);
	while (digits_length != 0)
		write(1, &digits[--digits_length], 1);
}
/*
int main(void)
{
    ft_putnbr_base(0, "zxc");
    write(1, "\n", 1);
    ft_putnbr_base(15, "0123456789");
    write(1, "\n", 1);
    ft_putnbr_base(-15, "0123456789");
    write(1, "\n", 1);
    ft_putnbr_base(15, "0123457890");
    write(1, "\n", 1);
    ft_putnbr_base(-15, "");
    write(1, "\n", 1);
    ft_putnbr_base(-15, "0");
    write(1, "\n", 1);
    ft_putnbr_base(15, "01");
    write(1, "\n", 1);
    ft_putnbr_base(-15, "01");
    write(1, "\n", 1);
    ft_putnbr_base(11, "01");
    write(1, "\n", 1);
    ft_putnbr_base(-11, "01");
    write(1, "\n", 1);
    ft_putnbr_base(15, "0123456789abcdef");
    write(1, "\n", 1);
    ft_putnbr_base(-15, "0123456789abcdef");
    write(1, "\n", 1);
    ft_putnbr_base(15, "abcdefghij");
    write(1, "\n", 1);
    ft_putnbr_base(-15, "abcdefghij");
    write(1, "\n", 1);
    ft_putnbr_base(0, "aa");
    write(1, "\n", 1);
}*/
