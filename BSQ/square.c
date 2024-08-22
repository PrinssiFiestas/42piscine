/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:03:55 by gpellech          #+#    #+#             */
/*   Updated: 2024/08/21 18:19:36 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

void	ft_find_biggest_sq(t_square *largest_sq, t_data map_data)
{
	size_t	i;
	size_t	j;
	size_t	sq_size;

	i = 0;
	while (i < map_data.rows)
	{
		j = 0;
		while (j < map_data.cols)
		{
			sq_size = max_sq_size(map_data, (t_point){j, i});
			if (sq_size > largest_sq->size)
				*largest_sq = (t_square){j, i, sq_size};
			++j;
		}
		++i;
	}
}

bool	ft_collision(t_point obstacle, t_point sq, size_t size)
{
	return (sq.x <= obstacle.x && obstacle.x < sq.x + size
		&& sq.y <= obstacle.y && obstacle.y < sq.y + size);
}

size_t	max_sq_size(t_data map_data, t_point sq)
{
	size_t	size;
	size_t	i;

	size = 1;
	while (sq.x + size <= map_data.cols && sq.y + size <= map_data.rows)
	{
		i = 0;
		while (i < map_data.obstacles_length)
		{
			if (ft_collision(map_data.obstacles[i], sq, size))
				return (size - 1);
			++i;
		}
		++size;
	}
	return (size - 1);
}
