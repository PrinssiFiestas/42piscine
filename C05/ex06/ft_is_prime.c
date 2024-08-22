/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:27:31 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 10:39:57 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divisors;

	if (nb < 2)
		return (0);
	divisors = 2;
	while (divisors * divisors <= nb)
	{
		if (nb % divisors == 0)
			return (0);
		++divisors;
	}
	return (1);
}
/*
#include <limits.h>
#include <assert.h>

int main(void)
{
    assert( ! ft_is_prime(-1));
    assert( ! ft_is_prime( 0));
    assert( ! ft_is_prime( 1));
    assert(   ft_is_prime( 2));
    assert(   ft_is_prime( 3));
    assert( ! ft_is_prime( 4));
    assert(   ft_is_prime( 5));
    assert( ! ft_is_prime( 6));
    assert(   ft_is_prime( 7));
    assert( ! ft_is_prime( 8));
    assert( ! ft_is_prime( 9));
    assert( ! ft_is_prime(10));
    assert(   ft_is_prime(11));
    assert( ! ft_is_prime(12));
}*/
