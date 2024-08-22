/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:17:44 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 10:38:34 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	while (nb != 0)
	{
		result *= nb;
		--nb;
	}
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
    printf("%i\n", ft_iterative_factorial(-5));
    printf("%i\n", ft_iterative_factorial(-1));
    printf("%i\n", ft_iterative_factorial(0));
    printf("%i\n", ft_iterative_factorial(1));
    printf("%i\n", ft_iterative_factorial(2));
    printf("%i\n", ft_iterative_factorial(3));
    printf("%i\n", ft_iterative_factorial(4));
    printf("%i\n", ft_iterative_factorial(5));
}*/
