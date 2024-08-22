/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:23:12 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/18 09:06:03 by lfiestas         ###   ########.fr       */
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

#define BUF_SIZE 4096

void	write_address(uintptr_t uaddr);
void	write_byte_values(const char *str, unsigned int size);
int		write_printable(const char *str, const char *addr, unsigned int size);

size_t	string_length(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result] != '\0')
		++result;
	return (result);
}

size_t	file_length(const char *path)
{
	int		fd;
	size_t	length;
	ssize_t	bytes_read;
	char	buf[BUF_SIZE];

	if (path[0] == '-' && path[1] == '\0')
		return (INT_MAX);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ((size_t) - 1);
	length = 0;
	bytes_read = -1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, sizeof buf);
		length += bytes_read;
	}
	close(fd);
	return (length);
}

#define DONE 1

void	*ft_print_memory(void *addr, unsigned int size)
{
	const char		*str;

	if (size == 0)
		return (addr);
	str = addr;
	while (1)
	{
		write_address(str - (char *)addr);
		write(1, ": ", 1);
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

int	print_file_error(const char *file_name)
{
	const char	*msg;

	msg = "ft_hexdump: cannot open '";
	write(2, msg, string_length(msg));
	write(2, file_name, string_length(file_name));
	msg = "' for reading: ";
	write(2, msg, string_length(msg));
	write(2, strerror(errno), string_length(strerror(errno)));
	write(2, "\n", 1);
	return (1);
}
