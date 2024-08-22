/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 10:33:08 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/14 08:29:49 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>
/*
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	size_t				length;
	struct s_stock_str	*tab;

	tab = malloc((ac + 1) * sizeof * tab);
	i = 0;
	while (i < ac)
	{
		tab[i].str = av[i];
		length = 0;
		while (av[i][length] != '\0')
			++length;
		tab[i].size = length;
		tab[i].copy = malloc(length + sizeof"");
		length = 0;
		while (av[i][length] != '\0')
		{
			tab[i].copy[length] = av[i][length];
			++length;
		}
		tab[i].copy[length] = '\0';
		++i;
	}
	tab[i].str = NULL;
	return (tab);
}
*/
void	ft_show_tab(struct s_stock_str *par)
{
	struct s_stock_str	copy;
	char				digits[12];
	size_t				digits_length;

	while (par->str != NULL)
	{
		copy = *par;
		write(1, copy.str, copy.size);
		write(1, "\n", 1);
		if (copy.size == 0)
			write(1, "0", 1);
		digits_length = 0;
		while (copy.size != 0)
		{
			digits[digits_length++] = copy.size % 10 + '0';
			copy.size /= 10;
		}
		while (digits_length != 0)
			write(1, &digits[--digits_length], 1);
		write(1, "\n", 1);
		while (copy.copy[0] != '\0')
			write(1, copy.copy++, 1);
		write(1, "\n", 1);
		++par;
	}
}
/*
int main(int argc, char** argv)
{
    t_stock_str* strs = ft_strs_to_tab(argc - 1, argv + 1);
    for (t_stock_str* p = strs; p->str != NULL; ++p)
        p->copy[1] = 'X';
    ft_show_tab(strs);
    for (t_stock_str* p = strs; p->str != NULL; ++p)
        free(p->copy);
    free(strs);
}*/
