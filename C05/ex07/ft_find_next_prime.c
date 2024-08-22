/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:34:58 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 10:40:07 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!is_prime(nb))
		++nb;
	return (nb);
}
/*
#include <stdio.h>
#include <assert.h>

int main(void)
{
    assert(ft_find_next_prime(-2) == 2);
    assert(ft_find_next_prime(-1) == 2);
    assert(ft_find_next_prime( 0) == 2);
    assert(ft_find_next_prime( 1) == 2);
    assert(ft_find_next_prime( 2) == 2);
    assert(ft_find_next_prime( 3) == 3);
    assert(ft_find_next_prime( 4) == 5);
    assert(ft_find_next_prime( 5) == 5);
    assert(ft_find_next_prime( 6) == 7);
    assert(ft_find_next_prime( 7) == 7);
    assert(ft_find_next_prime( 8) == 11);
    printf("%i\n", ft_find_next_prime(1000000000));
	assert(is_prime(ft_find_next_prime(1000000000)));
}*/
