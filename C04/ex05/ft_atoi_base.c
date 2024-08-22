/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:47:12 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/11 14:17:19 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long long int	convert_digits(char *str, char *base, unsigned int base_length)
{
	unsigned int	i;
	unsigned int	j;
	int				result;

	result = 0;
	i = 0;
	while (1)
	{
		j = 0;
		while (str[i] != base[j] && j < base_length)
			++j;
		if (j == base_length)
			break ;
		result = result * base_length + j;
		++i;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	i;
	unsigned int	base_length;
	long long int	sign;

	i = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		++i;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	base_length = validate_base(base);
	if (base_length == (unsigned int)-1)
		return (0);
	return (sign * convert_digits(str + i, base, base_length));
}
/*
#include <stdio.h>

int main(void)
{
    printf("%i\n", ft_atoi_base("  --+-425asdf", "0123456789"));
    printf("%i\n", ft_atoi_base("   -+-425asdf", "0123456789"));
    printf("%i\n", ft_atoi_base("\t  +++-1011asdf", "01"));
    printf("%i\n", ft_atoi_base("\t  ++++1011asdf", "01"));
    printf("%i\n", ft_atoi_base("\t  ++++BABBasdf", "AB"));
    printf("%i\n", ft_atoi_base("", "AB"));
    printf("%i\n", ft_atoi_base("-", "AB"));
    printf("%i\n", ft_atoi_base("bgrs", "AB"));
    printf("%i\n", ft_atoi_base("1011", ""));
    printf("%i\n", ft_atoi_base("1011", "1"));
    printf("%i\n", ft_atoi_base("1011", ""));
    printf("%i\n", ft_atoi_base("2147483647", "0123456789"));
    printf("%i\n", ft_atoi_base("-2147483648", "0123456789"));
}*/
