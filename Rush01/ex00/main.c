/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:00:23 by mquero            #+#    #+#             */
/*   Updated: 2024/08/11 18:04:03 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	sudoku_row(int x, int row, char grid[4][4]);
bool	sudoku_col(int y, int col, char grid[4][4]);
int		arrow_check_downward(int x, char grid[4][4]);
int		arrow_check_upward(int x, char grid[4][4]);
int		arrow_check_rightwards(int x, char grid[4][4]);
int		arrow_check_leftwards(int x, char grid[4][4]);
bool	validate(int edges[4][4], char grid[4][4]);
void	initialize_grid(char grid[4][4]);
void	print_grid(char grid[4][4]);
void	fill_grid(int limit, char grid[4][4], int edges[4][4]);

void	print_grid(char grid[4][4])
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			grid[x][y] += '0';
			write(1, &grid[x][y], 1);
			write(1, " ", 1);
			grid[x][y] -= '0';
			++y;
		}
		write (1, "\n", 1);
		++x;
	}
}
bool	g_found = false;

void	fill_grid(int limit, char grid[4][4], int edges[4][4])
{
	size_t	i;

	i = 1;
	if (g_found)
	{
		return ;
	}
	if (limit == 0)
	{
		g_found = validate(edges, grid);
		return ;
	}
	while (i <= 4 && !g_found)
	{
		grid[(16 - limit) / 4][(16 - limit) % 4] = i;
		fill_grid(limit - 1, grid, edges);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	grid[4][4];
	int		edges[4][4];
	size_t	i;

	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 31)
	{
		edges[(i / 2) / 4][(i / 2) % 4] = argv[1][i] - '0';
		i += 2;
	}
	initialize_grid (grid);
	fill_grid (16, grid, edges);
	print_grid (grid);
}
