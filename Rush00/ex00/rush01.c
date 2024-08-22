/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:49:47 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/04 13:51:49 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_corner(const int x, const int y, const int xi, const int yi)
{
	if ((y == 1 && xi == x - 1) || (x == 1 && yi == y - 1))
		ft_putchar('\\');
	else
		ft_putchar('/');
}

void	rush(int x, int y)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			if ((xi == 0 && yi == 0) || (xi == x - 1 && yi == y - 1))
				write_corner(x, y, xi, yi);
			else if ((xi == 0 && yi == y -1) || (xi == x - 1 && yi == 0))
				ft_putchar('\\');
			else if (xi == 0 || yi == 0 || xi == x - 1 || yi == y - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			++xi;
		}
		ft_putchar('\n');
		++yi;
	}
}
