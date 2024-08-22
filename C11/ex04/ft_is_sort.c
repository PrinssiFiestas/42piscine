/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:38:41 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/17 09:51:56 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	bool	sorted;

	sorted = true;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			sorted = false;
		++i;
	}
	i = 0;
	while (i < length - 1 && !sorted)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		++i;
	}
	return (1);
}
/*
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

int cmp(int a, int b)
{
	return a - b;
}

int main(void)
{
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 1, 2 };
	int arr3[] = { 4, 3, 2, 1 };
	int arr4[] = { 1 };
	int arr5[] = { 1, 3, 2, 4 };
	int arr6[] = { 4, 2, 3, 1 };
	int arr7[] = { 4, 3, 2, 1 };
	int arr8[] = { 2, 1, 1, 1 };
	int arr9[] = { 1, 1, 1, 2 };
	assert(ft_is_sort(arr1, sizeof arr1 / sizeof*arr1, cmp) == 1);
	assert(ft_is_sort(arr2, sizeof arr2 / sizeof*arr2, cmp) == 1);
	assert(ft_is_sort(arr3, sizeof arr3 / sizeof*arr3, cmp) == 1);
	assert(ft_is_sort(arr4, sizeof arr4 / sizeof*arr4, cmp) == 1);
	assert(ft_is_sort(arr5, sizeof arr5 / sizeof*arr5, cmp) == 0);
	assert(ft_is_sort(arr6, sizeof arr6 / sizeof*arr6, cmp) == 0);
	assert(ft_is_sort(arr7, sizeof arr7 / sizeof*arr7, cmp) == 1);
	assert(ft_is_sort(arr8, sizeof arr8 / sizeof*arr8, cmp) == 1);
	assert(ft_is_sort(arr9, sizeof arr9 / sizeof*arr9, cmp) == 1);
	assert(ft_is_sort(NULL, 0, cmp) == 1);
}*/
