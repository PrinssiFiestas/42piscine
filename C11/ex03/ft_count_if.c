/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:32:35 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/13 19:31:16 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		count += !!f(tab[i]);
		++i;
	}
	return (count);
}
/*
#include <stdio.h>
#include <stddef.h>
int is_empty(char* str)
{
	return !*str;
}

int main(void)
{
	char* arr1[] = {"asdf", "qwer", "zcxv", "1234"};
	char* arr2[] = {"asdf", "qwer", "", "1234"};
	char* arr3[] = {"asdf", "", "", "1234"};
	char* arr4[] = {"", "", "", ""};
	printf("%i %i %i %i\n",
		ft_count_if(arr1, 4, is_empty),
		ft_count_if(arr2, 4, is_empty),
		ft_count_if(arr3, 4, is_empty),
		ft_count_if(arr4, 4, is_empty));
}*/
