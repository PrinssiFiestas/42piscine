/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:03:22 by gpellech          #+#    #+#             */
/*   Updated: 2024/08/21 15:44:37 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

char	*ft_set_map(t_data *map_data)
{
	size_t	i;
	size_t	j;
	char	*map_mem;

	map_mem = malloc(map_data->rows * map_data->cols);
	map_data->map = malloc(map_data->rows * sizeof map_data->map[0]);
	i = 0;
	while (i < map_data->rows)
	{
		map_data->map[i] = map_mem + i * map_data->cols;
		++i;
	}
	i = 0;
	while (i < map_data->rows)
	{
		j = 0;
		while (j < map_data->cols)
		{
			map_data->map[i][j] = map_data->empty_char;
			++j;
		}
		++i;
	}
	return (map_mem);
}

int	ft_find_obst(t_data *map)
{
	int		map_fd;
	size_t	i;
	size_t	j;
	char	c;

	map_fd = 0;
	if (map->path[0] != '\0')
		map_fd = open(map->path, O_RDONLY);
	if (map_fd == -1)
		return (-1);
	c = 0;
	while (c != '\n')
		read(map_fd, &c, 1);
	map->obstacles = malloc(map->rows * map->cols * sizeof (map->obstacles[0]));
	map->obstacles_length = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			read(map_fd, &c, 1);
			if (c == map->obstacle_char)
			{
				map->obstacles[(map->obstacles_length)++] = (t_point){j, i};
				map->map[i][j] = map->obstacle_char;
			}
			++j;
		}
		read(map_fd, &c, 1);
		++i;
	}
	if (map_fd != 0)
		close(map_fd);
	return (0);
}

void	ft_draw_map(t_data map, t_square largest_sq)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.cols)
		{
			if (largest_sq.x <= j && j < largest_sq.x + largest_sq.size
				&& largest_sq.y <= i && i < largest_sq.y + largest_sq.size)
				write(1, &map.square_char, 1);
			else
				write(1, &map.map[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}
