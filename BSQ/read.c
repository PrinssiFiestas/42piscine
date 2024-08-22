/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:59:42 by gpellech          #+#    #+#             */
/*   Updated: 2024/08/21 17:23:02 by gpellech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	ft_set_chars(t_data *map, char *buffer, size_t buffer_length)
{
	map->empty_char = buffer[buffer_length - 3];
	map->obstacle_char = buffer[buffer_length - 2];
	map->square_char = buffer[buffer_length - 1];
	buffer[buffer_length - 3] = '\0';
	map->rows = ft_atoi(buffer);
	if (map->empty_char < 32 || map->empty_char > 126)
		return (-1);
	if (map->obstacle_char < 32 || map->obstacle_char > 126)
		return (-1);
	if (map->square_char < 32 || map->square_char > 126)
		return (-1);
	return (0);
}

int	ft_read_info(t_data *map)
{
	int		fd;
	char	c;
	char	buffer[128];
	size_t	buffer_length;

	fd = 0;
	if (map->path[0] != '\0')
		fd = open(map->path, O_RDONLY);
	buffer_length = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		buffer[buffer_length++] = c;
	}
	if (ft_buff_valid(fd, buffer, buffer_length) == -1)
		return (-1);
	if (ft_set_chars(map, buffer, buffer_length) == -1)
		return (ft_close(fd));
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		map->cols++;
	}
	if (fd != 0)
		close(fd);
	return (0);
}

int	ft_atoi(char *str)
{
	int	negs;
	int	digits;
	int	i;

	i = 0;
	negs = 0;
	digits = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			++negs;
		++i;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		digits *= 10;
		digits += str[i] - 48;
		++i;
	}
	if (negs % 2 == 1)
		digits *= -1;
	return (digits);
}

typedef struct s_check {
	size_t	rows;
	size_t	cols;
	bool	empty_found;
}	t_check;

int	ft_check_char(t_data map, char c, t_check *lines)
{
	if (c == '\n')
	{
		if (lines->cols != map.cols)
			return (-1);
		lines->cols = 0;
		++lines->rows;
		return (0);
	}
	if (c == map.empty_char)
		lines->empty_found = true;
	++lines->cols;
	if (c != map.empty_char && c != map.obstacle_char
		&& c != map.square_char)
		return (-1);
	return (0);
}

int	ft_valid_map(t_data map)
{
	int		fd;
	char	c;
	t_check lines;

	fd = 0;
	if (map.path[0] != '\0')
		fd = open(map.path, O_RDONLY);
	if (fd == -1)
		return (-1);
	c = '\0';
	while (c != '\n')
		read(fd, &c, 1);
	lines.rows = 0;
	lines.cols = 0;
	lines.empty_found = false;
	while (read(fd, &c, 1))
	{
		if (ft_check_char(map, c, &lines) == -1)
			return (ft_close(fd));
	}
	if (lines.rows != map.rows || !lines.empty_found)
		return (ft_close(fd));
	if (fd != 0)
		close(fd);
	return (0);
}

