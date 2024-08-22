/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiestas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:32:40 by lfiestas          #+#    #+#             */
/*   Updated: 2024/08/21 12:55:29 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libgen.h>

void	putstr(int fd, const char *str)
{
	while (*str != '\0')
		write(fd, str++, 1);
}

void	write_file_contents_to_stdout(int fd)
{
	char	c;

	while (read(fd, &c, 1))
		write(1, &c, 1);
}

void	print_error(const char *bin, const char *arg)
{
	putstr(2, bin);
	putstr(2, ": ");
	putstr(2, arg);
	putstr(2, ": ");
	putstr(2, strerror(errno));
	putstr(2, "\n");
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;

	if (argc == 1)
		write_file_contents_to_stdout(0);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			fd = 0;
		else
			fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			print_error(argv[0], argv[i]);
			++i;
			continue ;
		}
		write_file_contents_to_stdout(fd);
		if (fd != 0)
			close(fd);
		++i;
	}
}
