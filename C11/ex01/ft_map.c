/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:05:53 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/13 19:30:42 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	result = malloc(length * sizeof * result);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		++i;
	}
	return (result);
}
/*
#include <stdio.h>

int add2(int x)
{
	return x + 2;
}

int main(void)
{
	int  arr1[] = { 3, 5, 7, 9 };
	int* arr2 = ft_map(arr1, sizeof arr1 / sizeof*arr1, add2);
	for (size_t i = 0; i < sizeof arr1 / sizeof*arr2; ++i)
		printf("%i\n", arr2[i]);
	free(arr2);
}*/
