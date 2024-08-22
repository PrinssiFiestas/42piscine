/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:22:12 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 10:23:05 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <assert.h>

int main(void)
{
    assert(ft_recursive_power(-2, -2) ==  0);
    assert(ft_recursive_power(-2, -1) ==  0);
    assert(ft_recursive_power(-2,  0) ==  1);
    assert(ft_recursive_power(-2,  1) == -2);
    assert(ft_recursive_power(-2,  2) ==  4);
    assert(ft_recursive_power(-1, -2) ==  0);
    assert(ft_recursive_power(-1, -1) ==  0);
    assert(ft_recursive_power(-1,  0) ==  1);
    assert(ft_recursive_power(-1,  1) == -1);
    assert(ft_recursive_power(-1,  2) ==  1);
    assert(ft_recursive_power( 0, -2) ==  0);
    assert(ft_recursive_power( 0, -1) ==  0);
    assert(ft_recursive_power( 0,  0) ==  1);
    assert(ft_recursive_power( 0,  1) ==  0);
    assert(ft_recursive_power( 0,  2) ==  0);
    assert(ft_recursive_power( 1, -2) ==  0);
    assert(ft_recursive_power( 1, -1) ==  0);
    assert(ft_recursive_power( 1,  0) ==  1);
    assert(ft_recursive_power( 1,  1) ==  1);
    assert(ft_recursive_power( 1,  2) ==  1);
    assert(ft_recursive_power( 2, -2) ==  0);
    assert(ft_recursive_power( 2, -1) ==  0);
    assert(ft_recursive_power( 2,  0) ==  1);
    assert(ft_recursive_power( 2,  1) ==  2);
    assert(ft_recursive_power( 2,  2) ==  4);
    assert(ft_recursive_power( 3,  3) == 27);
}*/
