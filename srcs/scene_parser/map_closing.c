/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:22:07 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 15:22:17 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	is_col_t_d_closed(t_data *data, int col)
{
	int	row;
	int	wall_encountered;

	row = 0;
	wall_encountered = 0;
	while (row < data->map_h)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		row++;
	}
	return (1);
}

static int	is_col_b_t_closed(t_data *data, int col)
{
	int	row;
	int	wall_encountered;

	row = data->map_h - 1;
	wall_encountered = 0;
	while (row >= 0)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		row--;
	}
	return (1);
}

static int	is_row_l_r_closed(t_data *data, int row)
{
	int	col;
	int	wall_encountered;

	col = 0;
	wall_encountered = 0;
	while (col < data->map_w)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		col++;
	}
	return (1);
}

static int	is_row_r_l_closed(t_data *data, int row)
{
	int	col;
	int	wall_encountered;

	col = data->map_w - 1;
	wall_encountered = 0;
	while (col >= 0)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		col--;
	}
	return (1);
}

int	is_map_closed(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < data->map_h)
	{
		if (!is_row_l_r_closed(data, row) || !is_row_r_l_closed(data, row))
			return (ERR_MAP_NOT_CLOSED);
		row++;
	}
	while (col < data->map_w)
	{
		if (!is_col_t_d_closed(data, col) || !is_col_b_t_closed(data, col))
			return (ERR_MAP_NOT_CLOSED);
		col++;
	}
	return (SUCCESS);
}
