/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:19:32 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/11 10:08:37 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	validate_base(const char *base)
{
	size_t	base_length;
	size_t	i;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	base_length = 0;
	while (base[base_length] != 0)
	{
		if (base[base_length] == '+' || base[base_length] == '-')
			return (0);
		i = 0;
		while (i < base_length)
		{
			if (base[base_length] == base[i])
				return (0);
			++i;
		}
		++base_length;
	}
	return (1);
}

int	atoi_digits(char *str, size_t start, char *base, size_t base_length)
{
	size_t	i;
	size_t	j;
	int		result;

	result = 0;
	i = start;
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

int	atoi_base(char *str, char *base)
{
	size_t	i;
	size_t	base_length;
	int		sign;

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
	base_length = 0;
	while (base[base_length] != 0)
		++base_length;
	return (sign * atoi_digits(str, i, base, base_length));
}

size_t	itoa_base(char *digits, int nbr, char *base)
{
	size_t	digits_length;
	int		positive_nbr;
	size_t	base_length;

	if (nbr == 0)
	{
		digits[0] = base[0];
		return (1);
	}
	if (nbr >= 0)
		positive_nbr = nbr;
	else
		positive_nbr = -nbr;
	digits_length = 0;
	base_length = 0;
	while (base[base_length] != '\0')
		++base_length;
	while (positive_nbr != 0)
	{
		digits[digits_length++] = base[positive_nbr % base_length];
		positive_nbr /= base_length;
	}
	return (digits_length);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		i;
	size_t	length;
	char	digits[32];
	size_t	digits_length;

	if (!validate_base(base_from) || !validate_base(base_to))
		return (NULL);
	i = atoi_base(nbr, base_from);
	result = malloc(32 + sizeof"");
	result[0] = '\0';
	digits_length = itoa_base(digits, i, base_to);
	length = 0;
	if (nbr < 0)
		result[length++] = '-';
	while (digits_length != 0)
		result[length++] = digits[--digits_length];
	result[length] = '\0';
	return (result);
}
/*
#include <stdio.h>
#include <assert.h>

int main(void)
{
    char* str = ft_convert_base("   +---+11", "0123456789", "_|");
    puts(str);
    free(str);
    str = ft_convert_base("   +---+0", "0123456789", "_|");
    puts(str);
    free(str);
	assert(ft_convert_base("37", "01", "")  == NULL);
	assert(ft_convert_base("37", "01", "1") == NULL);
	assert(ft_convert_base("37", "01", "01234567890") == NULL);
	assert(ft_convert_base("37", "", "01")  == NULL);
	assert(ft_convert_base("37", "0", "01") == NULL);
	assert(ft_convert_base("37", "0120", "01") == NULL);
}*/
