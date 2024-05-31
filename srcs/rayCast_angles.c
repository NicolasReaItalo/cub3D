/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast_angles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:25:11 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/31 16:07:14 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static t_rayCast	_first_step(t_rayCast caster, t_data data)
{
	if (caster.ray.x < 0)
	{
		caster.stepx = -1;
		caster.sidedist.x = (data.pos.x - caster.case_x) * caster.delta.x;
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

static t_rayCast	_dist(t_rayCast caster)
{
	if (caster.sidedist.x < caster.sidedist.y)
	{
		caster.sidedist.x = caster.sidedist.x + caster.delta.x;
		caster.case_x = caster.case_x + caster.stepx;
		caster.side = 2;
		if (caster.ray.x < 0)
			caster.side = 0;
	}
	else
	{
		caster.sidedist.y = caster.sidedist.y + caster.delta.y;
		caster.case_y = caster.case_y + caster.stepy;
		caster.side = 3;
		if (caster.ray.y < 0)
			caster.side = 1;
	}
	return (caster);
}

static t_rayCast	_find_wall(t_rayCast caster, t_data data)
{
	while (caster.hit == 0)
	{
		caster = _dist(caster);
		if (data.map[caster.case_x][caster.case_y] > 0)
			caster.hit = 1;
	}
	if (caster.side == 0 || caster.side == 2)
		caster.walldist = caster.sidedist.x - caster.delta.x;
	else
		caster.walldist = caster.sidedist.y - caster.delta.y;
	return (caster);
}

void	ft_cast_angles(t_data data)
{
	double		x_cam;
	t_rayCast	caster;

	caster.x = 0;
	while (caster.x < SCREEN_W)
	{
		caster.hit = 0;
		x_cam = ((2 * caster.x) / (double)SCREEN_W) - 1;
		caster.ray.x = data.dir.x + data.cam.x * x_cam;
		caster.ray.y = data.dir.y + data.cam.y * x_cam;
		if (0 == caster.ray.x)
			caster.delta.x = 1e30;
		else
			caster.delta.x = fabs(1 / caster.ray.x);
		if (0 == caster.ray.y)
			caster.delta.y = 1e30;
		else
			caster.delta.y = fabs(1 / caster.ray.y);
		caster.case_x = (int)(data.pos.x);
		caster.case_y = (int)(data.pos.y);
		caster = _first_step(caster, data);
		caster = _find_wall(caster, data);
		ft_calculate(caster, data);
		caster.x++;
	}	
}
