/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:20:00 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/13 19:30:59 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	while (*tab)
	{
		if (f(*tab) != 0)
			return (1);
		++tab;
	}
	return (0);
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
	char* arr1[] = {"asdf", "qwer", "zcxv", "1234", NULL};
	char* arr2[] = {"asdf", "qwer", "", "1234", NULL};
	printf("%i %i\n", ft_any(arr1, is_empty), ft_any(arr2, is_empty));
}*/
