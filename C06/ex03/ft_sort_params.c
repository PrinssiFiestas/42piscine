/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:51:08 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/09 11:25:27 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	main(int argc, char **argv)
{
	int		i;
	size_t	arg_length;

	i = 1;
	while (i < argc - 1)
	{
		if (str_compare(argv[i], argv[i + 1]) > 0)
		{
			ptr_swap(&argv[i], &argv[i + 1]);
			i = 1;
		}
		else
			++i;
	}
	i = 1;
	while (i < argc)
	{
		arg_length = 0;
		while (argv[i][arg_length] != '\0')
			++arg_length;
		write(1, argv[i], arg_length);
		write(1, "\n", 1);
		++i;
	}
}
