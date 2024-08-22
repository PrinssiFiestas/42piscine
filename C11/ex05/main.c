/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:55:36 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/15 11:12:52 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef int(*		t_op)(int, int);

int					add(int a, int b);
int					sub(int a, int b);
int					div(int a, int b);
int					mul(int a, int b);
int					mod(int a, int b);

int	ret(int a, int b)
{
	(void)a;
	(void)b;
	return (0);
}

static const t_op	g_opfs[] = {add, sub, div, mul, mod, ret};
static const char	g_opcs[] = "+-/*%";

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				result;
	int				sign;

	result = 0;
	i = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		++i;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	return (sign * result);
}

size_t	op_i(char c)
{
	size_t	i;

	i = 0;
	while (i < sizeof g_opcs - 1 && g_opcs[i] != c)
		++i;
	return (i);
}

void	ft_putnbr(int nb)
{
	long long int	num;
	char			digits[16];
	unsigned int	digits_length;

	num = nb;
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	digits_length = 0;
	while (num != 0)
	{
		digits[digits_length++] = num % 10 + '0';
		num /= 10;
	}
	while (digits_length != 0)
		write(1, &digits[--digits_length], 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	size_t	i;
	int		a;
	int		b;

	if (argc != 4)
		return (0);
	i = op_i(argv[2][0]);
	if (i == sizeof g_opcs - 1 || argv[2][1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (g_opcs[i] == '/' && b == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (g_opcs[i] == '%' && b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_putnbr(g_opfs[i](a, b));
}
