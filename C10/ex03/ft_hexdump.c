/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:35:44 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/13 16:44:19 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	file_length(const char *path);
void	*ft_print_memory(void *addr, unsigned int size);
int		print_file_error(const char *file_name);
size_t	string_length(const char *str);

#define BUF_SIZE 4096

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
		if (i % 2 == 0)
			write(1, " ", 1);
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
		++i;
	}
	write(1, " ", 1);
}

#define DONE 1

int	write_printable(const char *str, const char *addr, unsigned int size)
{
	unsigned int	i;

	write(1, "|", 1);
	i = 0;
	while (i < 16)
	{
		if (str - addr + i == size)
		{
			write(1, "|", 1);
			return (DONE);
		}
		if (32 <= str[i] && str[i] != 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		++i;
	}
	write(1, "|", 1);
	return (0);
}

void	write_address(uintptr_t uaddr)
{
	char			buffer[16];
	unsigned int	i;

	i = 0;
	while (i < 8)
	{
		digit_to_hex_digit(&buffer[8 - 1 - i], uaddr);
		uaddr /= 8;
		++i;
	}
	write(1, buffer, 8);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*contents;
	size_t	contents_length;
	char	*path;

	(void)argc;
	path = argv[1];
	if (argv[1][0] == '-' && argv[1][1] == '\0')
		path = argv[2];
	contents_length = file_length(path);
	if (contents_length == (size_t) - 1)
		return (print_file_error(path));
	contents = malloc(contents_length + sizeof"");
	fd = open(path, O_RDONLY);
	read(fd, contents, contents_length);
	contents[contents_length] = '\0';
	if (fd == -1)
		return (print_file_error(path));
	ft_print_memory(contents, string_length(contents));
	free(contents);
}
