/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:28:32 by mquero            #+#    #+#             */
/*   Updated: 2024/08/11 17:52:00 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>

bool	sudoku_row(int x, int row, char grid[4][4])
{
	bool	found[4];
	int		i;

	while (row < 4)
	{	
		found[0] = false;
		found[1] = false;
		found[2] = false;
		found[3] = false;
		i = 0;
		while (i < 4)
		{
			x = 0;
			while (x < 4)
			{
				found[i] |= grid[row][x] == 1 + i;
				++x;
			}
			i++;
		}
		if (!found[0] || !found[1] || !found[2] || !found[3])
			return (false);
		++row;
	}
	return (true);
}

bool	sudoku_col(int y, int col, char grid[4][4])
{
	bool	found[4];
	int		i;

	while (col < 4)
	{	
		found[0] = false;
		found[1] = false;
		found[2] = false;
		found[3] = false;
		i = 0;
		while (i < 4)
		{
			y = 0;
			while (y < 4)
			{
				found[i] |= grid[y][col] == 1 + i;
				++y;
			}
			i++;
		}
		if (!found[0] || !found[1] || !found[2] || !found[3])
			return (false);
		++col;
	}
	return (true);
}
