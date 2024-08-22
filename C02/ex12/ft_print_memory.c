/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:35:44 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/07 11:04:33 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	digit_to_hex_digit(char *out, uintptr_t in)
{
	if (in % 16 < 10)
		*out = in % 16 + '0';
	else
		*out = in % 16 - 10 + 'a';
}

void	write_byte_values(const char *str, unsigned int size)
{
	unsigned int	i;
	char			buffer[4];

	i = 0;
	while (i < 16)
	{
		if (i >= size)
			write(1, "  ", 2);
		else
		{
			if (str[i] / 0x10 < 10)
				buffer[0] = str[i] / 0x10 + '0';
			else
				buffer[0] = str[i] / 0x10 - 10 + 'a';
			if (str[i] % 0x10 < 10)
				buffer[1] = str[i] % 0x10 + '0';
			else
				buffer[1] = str[i] % 0x10 - 10 + 'a';
			write(1, buffer, 2);
		}
		if (i % 2 == 0)
			write(1, " ", 1);
		++i;
	}
	write(1, " ", 1);
}

#define DONE 1

int	write_printable(const char *str, const char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (str - addr + i == size)
		{
			return (DONE);
		}
		if (32 <= str[i] && str[i] != 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		++i;
	}
	return (0);
}

void	write_address(uintptr_t uaddr)
{
	char			buffer[16];
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		digit_to_hex_digit(&buffer[16 - 1 - i], uaddr);
		uaddr /= 16;
		++i;
	}
	write(1, buffer, 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	const char		*str;

	if (size == 0)
		return (addr);
	str = addr;
	while (1)
	{
		write_address((uintptr_t)str);
		write(1, ":", 1);
		write_byte_values(str, size - (str - (char *)addr));
		if (write_printable(str, addr, size) == DONE)
		{
			write(1, "\n", 1);
			return (addr);
		}
		write(1, "\n", 1);
		str += 16;
	}
	return (addr);
}
