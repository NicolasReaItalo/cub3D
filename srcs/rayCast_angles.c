/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast_angles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:25:11 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/28 17:08:36 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_rayCast	first_step(t_rayCast caster, t_data data)
{
	if (caster.ray.x < 0)
	{
		caster.stepx = -1;
		caster.sidedist.x = (data.pos.x - caster.case_x)* caster.delta.x;
	}
	else
	{
		caster.stepx = 1;
		caster.sidedist.x = (caster.case_x + 1 - data.pos.x) * caster.delta.x;
	}
	if (caster.ray.y < 0)
	{
		caster.stepy = -1;
		caster.sidedist.y = (data.pos.y - caster.case_y) * caster.delta.y;
	}	
	else
	{
		caster.stepy = 1;
		caster.sidedist.y = (caster.case_y + 1 - data.pos.y) * caster.delta.y;
	}
	return (caster);

}

t_rayCast find_wall(t_rayCast caster, t_data data)
{
	while (caster.hit == 0)
	{
		if (caster.sidedist.x < caster.sidedist.y)
		{
			caster.sidedist.x = caster.sidedist.x + caster.delta.x;
			caster.case_x = caster.case_x + caster.stepx;
			if (caster.ray.x < 0)
				caster.side = 0;
			else
				caster.side = 2;
		}
		else
		{
			caster.sidedist.y = caster.sidedist.y + caster.delta.y;
			caster.case_y = caster.case_y + caster.stepy;
			if (caster.ray.y < 0)
				caster.side = 1;
			else
				caster.side = 3;
		}
		if (data.map[caster.case_x][caster.case_y] > 0)
			caster.hit = 1;
	}
	if (caster.side == 0 || caster.side == 2)
		caster.wallDist = caster.sidedist.x - caster.delta.x;
	else
		caster.wallDist = caster.sidedist.y - caster.delta.y;
	return (caster);
}

void drawline(t_rayCast caster, int start, int end, t_data data)
{
	int y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < start)			
			ft_pixel(&data.screen_img, caster.x, y, 0x0000DD);
			
				
		else if (y > end)
			ft_pixel(&data.screen_img, caster.x, y, 0xC19A6B);
		else
		{
			if (caster.side == 0)
				ft_pixel(&data.screen_img, caster.x, y, 0xFF0000);
			else if (caster.side == 1)
				ft_pixel(&data.screen_img, caster.x, y, 0x00FF00);
			else if (caster.side == 2)
				ft_pixel(&data.screen_img, caster.x, y, 0x880000);
			else
				ft_pixel(&data.screen_img, caster.x, y, 0x008800);
		}
		y++;
	}
}

void	draw(t_rayCast caster, t_data data)
{
	int	height;
	int	start;
	int end;

	height = (int)(SCREEN_HEIGHT / caster.wallDist);

	start = fmax(SCREEN_HEIGHT / 2 - (height / 2), 0);
	end = fmin(SCREEN_HEIGHT / 2 + (height / 2), SCREEN_HEIGHT);
	drawline(caster, start, end, data);
}

void	cast_angles(t_data data)
{
	double		x_cam;
	t_rayCast	caster;

	caster.x = 0;
	while (caster.x < SCREEN_WIDTH)
	{
		caster.hit = 0;
		x_cam = ((2 * caster.x) / (double)SCREEN_WIDTH) -1;
		caster.ray.x = data.dir.x + data.cam.x * x_cam;
		caster.ray.y = data.dir.y + data.cam.y * x_cam;
		caster.delta.x = (caster.ray.x == 0) ? 1e30 : fabs(1 / caster.ray.x);
		caster.delta.y = (caster.ray.y == 0) ? 1e30 : fabs(1 / caster.ray.y);
		caster.case_x = (int)(data.pos.x);
		caster.case_y = (int)(data.pos.y);
		caster = first_step(caster, data);
		caster = find_wall(caster, data);
		draw(caster, data);
		caster.x++;
	}	
}


