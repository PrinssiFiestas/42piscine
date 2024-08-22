/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:47:22 by mquero            #+#    #+#             */
/*   Updated: 2024/08/11 18:05:31 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdbool.h>

bool	sudoku_row(int x, int row, char grid[4][4]);
bool	sudoku_col(int y, int col, char grid[4][4]);
int		arrow_check_downward(int x, char grid[4][4]);
int		arrow_check_upward(int x, char grid[4][4]);
int		arrow_check_rightwards(int x, char grid[4][4]);
int		arrow_check_leftwards(int x, char grid[4][4]);

bool	validate_sudoku(char grid[4][4])
{	
	int	row;
	int	col;
	int	x;
	int	y;

	x = 0;
	y = 0;
	row = 0;
	col = 0;
	if (!sudoku_row(x, row, grid))
		return (false);
	if (!sudoku_col(y, col, grid))
		return (false);
	return (true);
}

bool	validate_arrow(int edges[4][4], char grid[4][4])
{
	int	y;
	int	x;
	int	arrow_count;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (y == 0)
				arrow_count = arrow_check_downward(x, grid);
			else if (y == 1)
				arrow_count = arrow_check_upward(x, grid);
			else if (y == 2)
				arrow_count = arrow_check_rightwards(x, grid);
			else
				arrow_count = arrow_check_leftwards(x, grid);
			if (arrow_count != edges[y][x])
				return (false);
			++x;
		}
		++y;
	}
	return (true);
}

bool	validate(int edges[4][4], char grid[4][4])
{
	if (!validate_sudoku(grid))
		return (false);
	if (!validate_arrow(edges, grid))
		return (false);
	return (true);
}

void	initialize_grid(char grid[4][4])
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			grid[y][x] = 1;
			++x;
		}
		++y;
	}
}
