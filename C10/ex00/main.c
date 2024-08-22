/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:20 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/07 12:20:01 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	putstr(int fd, const char *str)
{
	while (*str != '\0')
		write(fd, str++, 1);
}

int	validate_arg_count(int argc)
{
	if (argc < 2)
	{
		putstr(2, "File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		putstr(2, "Too many arguments.\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	buf[4096];
	ssize_t	bytes_read;

	if (!validate_arg_count(argc))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		putstr(2, "Cannot read file.\n");
		return (1);
	}
	bytes_read = -1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, sizeof buf);
		write(1, buf, bytes_read);
	}
	close(fd);
}
