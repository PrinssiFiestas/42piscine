/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:24:50 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 11:39:59 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ptr_swap(char **p1, char **p2)
{
	char	*swap;

	swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}

void	ft_advanced_sort_string_tab(char **argv, int (*cmp)(char *, char *))
{
	size_t	i;
	size_t	argc;

	argc = 0;
	while (argv[argc] != NULL)
		++argc;
	i = 0;
	while (i < argc - !!argc)
	{
		if (cmp(argv[i], argv[i + 1]) > 0)
		{
			ptr_swap(&argv[i], &argv[i + 1]);
			i = 0;
		}
		else
			++i;
	}
}
/*
#include <stdio.h>
int	str_compare(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		++str1;
		++str2;
	}
	return (0);
}

int main(int argc, char** argv)
{
	--argc;
	++argv;
	ft_advanced_sort_string_tab(argv, str_compare);
	for (size_t i = 0; i < (size_t)argc; ++i)
		printf("%s\n", argv[i]);
}*/
