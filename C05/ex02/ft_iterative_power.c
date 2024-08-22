/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:19:56 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 10:39:18 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power != 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <assert.h>

int main(void)
{
    assert(ft_iterative_power(-2, -2) ==  0);
    assert(ft_iterative_power(-2, -1) ==  0);
    assert(ft_iterative_power(-2,  0) ==  1);
    assert(ft_iterative_power(-2,  1) == -2);
    assert(ft_iterative_power(-2,  2) ==  4);
    assert(ft_iterative_power(-1, -2) ==  0);
    assert(ft_iterative_power(-1, -1) ==  0);
    assert(ft_iterative_power(-1,  0) ==  1);
    assert(ft_iterative_power(-1,  1) == -1);
    assert(ft_iterative_power(-1,  2) ==  1);
    assert(ft_iterative_power( 0, -2) ==  0);
    assert(ft_iterative_power( 0, -1) ==  0);
    assert(ft_iterative_power( 0,  0) ==  1);
    assert(ft_iterative_power( 0,  1) ==  0);
    assert(ft_iterative_power( 0,  2) ==  0);
    assert(ft_iterative_power( 1, -2) ==  0);
    assert(ft_iterative_power( 1, -1) ==  0);
    assert(ft_iterative_power( 1,  0) ==  1);
    assert(ft_iterative_power( 1,  1) ==  1);
    assert(ft_iterative_power( 1,  2) ==  1);
    assert(ft_iterative_power( 2, -2) ==  0);
    assert(ft_iterative_power( 2, -1) ==  0);
    assert(ft_iterative_power( 2,  0) ==  1);
    assert(ft_iterative_power( 2,  1) ==  2);
    assert(ft_iterative_power( 2,  2) ==  4);
    assert(ft_iterative_power( 3,  3) == 27);
}*/
