/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:24:50 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 11:40:09 by lfiestas         ###   ########.fr       */
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

int	str_compare(const char *str1, const char *str2)
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

void	ft_sort_string_tab(char **argv)
{
	size_t	i;
	size_t	argc;

	argc = 0;
	while (argv[argc] != NULL)
		++argc;
	i = 0;
	while (i < argc - !!argc)
	{
		if (str_compare(argv[i], argv[i + 1]) > 0)
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
int main(int argc, char** argv)
{
	--argc;
	++argv;
	ft_sort_string_tab(argv);
	for (size_t i = 0; i < (size_t)argc; ++i)
		printf("%s\n", argv[i]);
}*/
