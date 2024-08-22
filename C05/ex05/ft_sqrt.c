/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:24:58 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/12 19:21:42 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 0;
	while (result <= nb)
	{
		if (result * result == nb)
			return (result);
		++result;
	}
	return (0);
}
/*
#include <stdio.h>
#include <assert.h>

int main(void)
{
	assert(ft_sqrt(100)==10);
    assert(ft_sqrt(27) == 0);
    assert(ft_sqrt(25) == 5);
    assert(ft_sqrt(24) == 0);
    assert(ft_sqrt(17) == 0);
    assert(ft_sqrt(16) == 4);
    assert(ft_sqrt(15) == 0);
    assert(ft_sqrt(10) == 0);
    assert(ft_sqrt( 9) == 3);
    assert(ft_sqrt( 8) == 0);
    assert(ft_sqrt( 5) == 0);
    assert(ft_sqrt( 4) == 2);
    assert(ft_sqrt( 3) == 0);
    assert(ft_sqrt( 2) == 0);
    assert(ft_sqrt( 1) == 1);
    assert(ft_sqrt( 0) == 0);
    assert(ft_sqrt(-1) == 0);
    assert(ft_sqrt(-2) == 0);
    assert(ft_sqrt(-3) == 0);
    printf("%i\n", ft_sqrt(100000000));
}*/
