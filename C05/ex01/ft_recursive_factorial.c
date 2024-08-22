/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:38:46 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/12 14:37:37 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>

int main(void)
{
    printf("%i\n", ft_recursive_factorial(-5));
    printf("%i\n", ft_recursive_factorial(-1));
    printf("%i\n", ft_recursive_factorial(0));
    printf("%i\n", ft_recursive_factorial(1));
    printf("%i\n", ft_recursive_factorial(2));
    printf("%i\n", ft_recursive_factorial(3));
    printf("%i\n", ft_recursive_factorial(4));
    printf("%i\n", ft_recursive_factorial(5));
}*/
