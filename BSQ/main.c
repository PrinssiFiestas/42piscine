/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:04:23 by gpellech          #+#    #+#             */
/*   Updated: 2024/08/21 18:02:35 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "bsq.h"

void	ft_free_all(t_data map, char *map_mem)
{
	free(map.map);
	free(map.obstacles);
	free(map_mem);
}

int ft_create_temp_map(const char *path)
{
	int		fd;
	char	c;

	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	while (read(0, &c, 1))
		write(fd, &c, 1);
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	int			error;
	char		*map_mem;
	t_data		map;
	t_square	largest_sq;

	if (argc == 1)
	{
		argv[argc++] = "temp.txt";
		if (ft_create_temp_map("temp.txt") == -1)
		{
			write(2, "ERROR\n", 6);
			return (-1);
		}
	} // TODO remove stdin chwecks
	i = 1;
	while (i < argc)
	{
		map = (t_data){.path = argv[i]};
		largest_sq = (t_square){};
		error = ft_read_info(&map);
		map_mem = NULL;
		if (error != -1)
			map_mem = ft_set_map(&map);
		if (error != -1)
			error = ft_valid_map(map);
		if (error != -1)
			error = ft_find_obst(&map);
		if (error != -1)
			ft_find_biggest_sq(&largest_sq, map);
		if (error != -1)
			ft_draw_map(map, largest_sq);
		if (error == -1)
			write(1, "map error\n", 10);
		ft_free_all(map, map_mem);
		++i;
	}

	return (0);
}
