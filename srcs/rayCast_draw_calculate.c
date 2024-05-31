/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast_draw_calculate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:19:24 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/31 16:24:46 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static t_draw_p	_texx(t_rayCast caster, t_draw_p p, t_data data, double wall_x)
{
	p.texs = (int)((wall_x - floor(wall_x)) * data.s_img.width);
	if ((caster.side == 0 || caster.side == 2) && caster.ray.x > 0)
		p.texs = data.s_img.width - p.texs - 1;
	if ((caster.side == 1 || caster.side == 3) && caster.ray.y < 0)
		p.texs = data.s_img.width - p.texs - 1;
	p.texe = (int)((wall_x - floor(wall_x)) * data.e_img.width);
	if ((caster.side == 0 || caster.side == 2) && caster.ray.x > 0)
		p.texe = data.e_img.width - p.texe - 1;
	if ((caster.side == 1 || caster.side == 3) && caster.ray.y < 0)
		p.texe = data.e_img.width - p.texe - 1;
	p.texw = (int)((wall_x - floor(wall_x)) * data.w_img.width);
	if ((caster.side == 0 || caster.side == 2) && caster.ray.x > 0)
		p.texw = data.w_img.width - p.texw - 1;
	if ((caster.side == 1 || caster.side == 3) && caster.ray.y < 0)
		p.texw = data.w_img.width - p.texw - 1;
	p.texn = (int)((wall_x - floor(wall_x)) * data.n_img.width);
	if ((caster.side == 0 || caster.side == 2) && caster.ray.x > 0)
		p.texn = data.n_img.width - p.texn - 1;
	if ((caster.side == 1 || caster.side == 3) && caster.ray.y < 0)
		p.texn = data.n_img.width - p.texn - 1;
	p.texn *= data.n_img.img.bpp / 8;
	p.texs *= data.s_img.img.bpp / 8;
	p.texe *= data.e_img.img.bpp / 8;
	p.texw *= data.w_img.img.bpp / 8;
	return (p);
}

static void	_drawline(t_rayCast caster, int start, int end, t_data data)
{
	t_draw_p	p;
	double		wall_x;

	p.start = start;
	p.end = end;
	if (caster.side == 1 || caster.side == 3)
		wall_x = data.pos.x + caster.walldist * caster.ray.x;
	else
		wall_x = data.pos.y + caster.walldist * caster.ray.y;
	p = _texx(caster, p, data, wall_x);
	p.y = 0;
	p.nstep = (data.n_img.height) / (double)(p.end - p.start);
	p.sstep = (data.s_img.height) / (double)(p.end - p.start);
	p.estep = (data.e_img.height) / (double)(p.end - p.start);
	p.wstep = (data.w_img.height) / (double)(p.end - p.start);
	while (p.y < SCREEN_H)
	{
		if (p.y < start)
			ft_pixel(&data.screen_img, caster.x, p.y, data.c_color);
		else if (p.y >= end)
			ft_pixel(&data.screen_img, caster.x, p.y, data.f_color);
		else
			draw_dispatch(caster, data, p);
		p.y++;
	}
}

void	ft_calculate(t_rayCast caster, t_data data)
{
	int	height;
	int	start;
	int	end;

	caster.x_shift = fmax(0, (caster.x - 1)) * data.screen_img.bpp / 8;
	height = (int)(SCREEN_H / caster.walldist);
	start = (SCREEN_H / 2 - (height / 2));
	end = (SCREEN_H / 2 + (height / 2));
	_drawline(caster, start, end, data);
}
