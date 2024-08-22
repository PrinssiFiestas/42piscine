/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:02:48 by gpellech          #+#    #+#             */
/*   Updated: 2024/08/21 15:41:01 by lfiestas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

typedef struct s_square
{
	size_t	x;
	size_t	y;
	size_t	size;
}	t_square;

typedef struct s_pgm_data
{
	size_t	rows;
	size_t	cols;
	char	*path;
	t_point	*obstacles;
	size_t	obstacles_length;
	char	**map;
	char	empty_char;
	char	obstacle_char;
	char	square_char;
}	t_data;

void	ft_find_biggest_sq(t_square *largest_sq, t_data map_data);
bool	ft_collision(t_point obstacle, t_point sq, size_t size);
size_t	max_sq_size(t_data map_data, t_point sq);
char	*ft_set_map(t_data *map_data);
int		ft_find_obst(t_data *map_data);
void	ft_draw_map(t_data map_data, t_square largest_sq);
int		ft_read_info(t_data *map_data);
int		ft_valid_char(t_data map);
int		ft_valid_map(t_data map);
int		ft_close(int fd);
int		ft_atoi(char *str);
int		ft_buff_valid(int fd, char *buffer, size_t buffer_length);

#endif
