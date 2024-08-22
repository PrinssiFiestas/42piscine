/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:56 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/08 16:07:18 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				result;
	int				sign;

	result = 0;
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
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	return (sign * result);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%i\n", ft_atoi(" \t \n \v \f --+-+163asdf43"));
    printf("%i\n", ft_atoi(" \t \n \v \f ---+-+163asdf43"));
    printf("%i\n", ft_atoi(""));
    printf("%i\n", ft_atoi("  -0;;"));
    printf("%i\n", ft_atoi("  -1;;"));
}*/
