/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@studet.hive.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:40:20 by mquero            #+#    #+#             */
/*   Updated: 2024/08/11 14:09:41 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arrow_check_downward(int x, char grid[4][4])
{
	int	arrow;
	int	arrow_length;
	int	last_arrow_length;
	int	arrow_count;
	int	col;

	col = x;
	arrow = 1;
	last_arrow_length = -1;
	arrow_count = 0;
	while (arrow <= 4)
	{
		arrow_length = 0;
		while (arrow_length < 4)
		{
			if (arrow <= grid[arrow_length][col])
				break ;
			++arrow_length;
		}
		if (arrow_length != last_arrow_length)
			++arrow_count;
		last_arrow_length = arrow_length;
		++arrow;
	}
	return (arrow_count);
}

int	arrow_check_upward(int x, char grid[4][4])
{
	int	arrow;
	int	arrow_length;
	int	last_arrow_length;
	int	arrow_count;
	int	col;

	col = x;
	arrow = 1;
	last_arrow_length = -1;
	arrow_count = 0;
	while (arrow <= 4)
	{
		arrow_length = 0;
		while (arrow_length < 4)
		{
			if (arrow <= grid[3 - arrow_length][col])
				break ;
			++arrow_length;
		}
		if (arrow_length != last_arrow_length)
			++arrow_count;
		last_arrow_length = arrow_length;
		++arrow;
	}
	return (arrow_count);
}

int	arrow_check_rightwards(int x, char grid[4][4])
{
	int	arrow;
	int	arrow_length;
	int	last_arrow_length;
	int	arrow_count;
	int	row;

	row = x;
	arrow = 1;
	last_arrow_length = -1;
	arrow_count = 0;
	while (arrow <= 4)
	{
		arrow_length = 0;
		while (arrow_length < 4)
		{
			if (arrow <= grid[row][arrow_length])
				break ;
			++arrow_length;
		}
		if (arrow_length != last_arrow_length)
			++arrow_count;
		last_arrow_length = arrow_length;
		++arrow;
	}
	return (arrow_count);
}

int	arrow_check_leftwards(int x, char grid[4][4])
{
	int	arrow;
	int	arrow_length;
	int	last_arrow_length;
	int	arrow_count;
	int	row;

	row = x;
	arrow = 1;
	last_arrow_length = -1;
	arrow_count = 0;
	while (arrow <= 4)
	{
		arrow_length = 0;
		while (arrow_length < 4)
		{
			if (arrow <= grid[row][3 - arrow_length])
				break ;
			++arrow_length;
		}
		if (arrow_length != last_arrow_length)
			++arrow_count;
		last_arrow_length = arrow_length;
		++arrow;
	}
	return (arrow_count);
}
