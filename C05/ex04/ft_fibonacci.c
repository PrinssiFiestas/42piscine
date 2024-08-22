/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:23:16 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/13 18:28:10 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
/*
#include <assert.h>

int main(void)
{
    assert(ft_fibonacci(-2) ==-1);
    assert(ft_fibonacci(-1) ==-1);
    assert(ft_fibonacci( 0) == 0);
    assert(ft_fibonacci( 1) == 1);
    assert(ft_fibonacci( 2) == 1);
    assert(ft_fibonacci( 3) == 2);
    assert(ft_fibonacci( 4) == 3);
    assert(ft_fibonacci( 5) == 5);
    assert(ft_fibonacci( 6) == 8);
    assert(ft_fibonacci( 7) ==13);
}*/
