/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:34:07 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/21 12:57:46 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>
#include <libgen.h>

int		ft_atoi(const char *str);
size_t	string_length(const char *str);
int		print_file_error(const char *bin, const char *file_name);

#define BUF_SIZE 2048

struct s_cflag
{
	size_t	count;
	size_t	index;
	size_t	index1;
};

struct s_cflag	find_cflag(int argc, char *argv[])
{
	int				i;
	struct s_cflag	cflag;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'c')
		{
			cflag.index = i;
			if (argv[i][2] == '\0')
			{
				cflag.index1 = i + 1;
				cflag.count = ft_atoi(argv[i + 1]);
			}
			else
			{
				cflag.index1 = i;
				cflag.count = ft_atoi(argv[i] + 2);
			}
		}
		++i;
	}
	return (cflag);
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

size_t	write_tail(const char *path, size_t file_length, size_t count)
{
	int		fd;
	size_t	i;
	ssize_t	bytes_read;
	char	buf[BUF_SIZE];

	fd = 0;
	if (!(path[0] == '-' && path[1] == '\0'))
		fd = open(path, O_RDONLY);
	if (fd == -1)
		return ((size_t) - 1);
	if (file_length < count)
		count = file_length;
	i = 0;
	while (i < file_length - count)
	{
		read(fd, buf, 1);
		++i;
	}
	bytes_read = -1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, sizeof buf);
		write(1, buf, bytes_read);
	}
	return (i);
}

void	write_header(char *file_name)
{
	static bool	first_arg = true;

	if (!first_arg)
		write(1, "\n", 1);
	first_arg = false;
	write(1, "==> ", 4);
	if (file_name[0] == '-' && file_name[1] == '\0')
		write(1, "standard input", 14);
	else
		write(1, file_name, string_length(file_name));
	write(1, " <==\n", 5);
}

int	main(int argc, char *argv[])
{
	size_t			i;
	size_t			flen;
	struct s_cflag	cflag;

	cflag = find_cflag(argc, argv);
	if (argc == 2 + (cflag.index != cflag.index1))
		argv[argc++] = "-";
	i = 1;
	while (i < (size_t)argc)
	{
		if (i != cflag.index && i != cflag.index1)
		{
			flen = file_length(argv[i]);
			if (flen == (size_t) - 1)
			{
				print_file_error(argv[0], argv[i++]);
				continue ;
			}
			if (argc > 3 + (cflag.index != cflag.index1))
				write_header(argv[i]);
			if (!write_tail(argv[i], flen, cflag.count))
				return (print_file_error(argv[0], argv[i]));
		}
		++i;
	}
}
