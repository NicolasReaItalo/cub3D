/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:28:59 by nrea              #+#    #+#             */
/*   Updated: 2024/05/28 17:18:01 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_keypress(int key, t_data *data)
{
	double rotmat[2][2] = {{cos(ALPHA), -sin(ALPHA)},{sin(ALPHA), cos(ALPHA)}};
	double negrotmat[2][2] = {{cos(-ALPHA), -sin(-ALPHA)},{sin(-ALPHA), cos(-ALPHA)}};
	double tmpx;
	double tmpy;
	if (key == XK_Escape)
		ft_destroy_window(data);
	
	
	else if (key == XK_Left)
	{
		data->dir = ft_apply2dmat(data->dir, rotmat);
		data->cam = ft_apply2dmat(data->cam, rotmat);
		printf("Left key pressed - %f %f\n", data->dir.x, data->dir.y);
	}
	else if (key == XK_Right)
	{
		data->dir = ft_apply2dmat(data->dir, negrotmat);
		data->cam = ft_apply2dmat(data->cam, negrotmat);
		printf("Right key pressed - %f %f\n", data->dir.x, data->dir.y);
	}

	
	else if (key == XK_a)
	{
		tmpx = data->pos.x - data->pos.x * (data->dir.y * SPEED);
		tmpy = data->pos.y + data->pos.y * (data->dir.x * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
		printf("A key pressed - %f %f\n", data->pos.x, data->pos.y);
	}
	else if (key == XK_w)
	{
		tmpx = data->pos.x + data->pos.x * (data->dir.x * SPEED);
		tmpy = data->pos.y + data->pos.y * (data->dir.y * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
		printf("W key pressed - %f %f\n", data->pos.x, data->pos.y);
	}
	else if (key == XK_s)
	{
		tmpx = data->pos.x - data->pos.x * (data->dir.x * SPEED);
		tmpy = data->pos.y - data->pos.y * (data->dir.y * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
		printf("S key pressed - %f %f\n", data->pos.x, data->pos.y);
	}
	else if (key == XK_d)
	{
		tmpx = data->pos.x + data->pos.x * (data->dir.y * SPEED);
		tmpy = data->pos.y - data->pos.y * (data->dir.x * SPEED);
		if (1 != data->map[(int)tmpx][(int)tmpy])
		{
			data->pos.x = tmpx;
			data->pos.y = tmpy;
		}
		printf("D key pressed - %f %f\n", data->pos.x, data->pos.y);
	}
	return (0);
}
