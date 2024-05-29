/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:43:23 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/29 13:52:23 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_rotate(t_data *data)
{
	double	rotmat[2][2];
	double	negrotmat[2][2];

	rotmat[0][0] = cos(ALPHA);
	rotmat[0][1] = -sin(ALPHA);
	rotmat[1][0] = sin(ALPHA);
	rotmat[1][1] = cos(ALPHA);
	negrotmat[0][0] = cos(-ALPHA);
	negrotmat[0][1] = -sin(-ALPHA);
	negrotmat[1][0] = sin(-ALPHA);
	negrotmat[1][1] = cos(-ALPHA);
	if (data->keypress[4] == 1)
	{
		data->dir = ft_apply2dmat(data->dir, rotmat);
		data->cam = ft_apply2dmat(data->cam, rotmat);
	}
	if (data->keypress[5] == 1)
	{
		data->dir = ft_apply2dmat(data->dir, negrotmat);
		data->cam = ft_apply2dmat(data->cam, negrotmat);
	}
}

static void	ft_forward(t_data *data)
{
	double	tmpx;
	double	tmpy;

	if (data->keypress[0] == 1)
	{
		tmpx = data->pos.x + data->pos.x * (data->dir.x * SPEED);
		tmpy = data->pos.y + data->pos.y * (data->dir.y * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
	}
	if (data->keypress[1] == 1)
	{
		tmpx = data->pos.x - data->pos.x * (data->dir.x * SPEED);
		tmpy = data->pos.y - data->pos.y * (data->dir.y * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
	}
}

static void	ft_backward(t_data *data)
{
	double	tmpx;
	double	tmpy;

	if (data->keypress[2] == 1)
	{
		tmpx = data->pos.x - data->pos.x * (data->dir.y * SPEED);
		tmpy = data->pos.y + data->pos.y * (data->dir.x * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
	}
	if (data->keypress[3] == 1)
	{
		tmpx = data->pos.x + data->pos.x * (data->dir.y * SPEED);
		tmpy = data->pos.y - data->pos.y * (data->dir.x * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
	}
}

int	ft_keyact(t_data *data)
{
	ft_backward(data);
	ft_forward(data);
	ft_rotate(data);
	return (0);
}
