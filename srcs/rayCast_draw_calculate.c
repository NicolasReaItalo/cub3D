/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast_draw_calculate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:19:24 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/30 11:27:45 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	drawline(t_rayCast caster, int start, int end, t_data data)
{
	t_draw_p	p;
	double		wall_x;

	p.start = start;
	p.end = end;
	if (caster.side == 1 || caster.side == 3)
		wall_x = data.pos.x + caster.walldist * caster.ray.x;
	else
		wall_x = data.pos.y + caster.walldist * caster.ray.y;
	p.texX = (int)((wall_x - floor(wall_x)) * data.n_img.width);
	if ((caster.side == 0 || caster.side == 2) && caster.ray.x > 0)
		p.texX = data.n_img.width - p.texX - 1;
	if ((caster.side == 1 || caster.side == 3) && caster.ray.y < 0)
		p.texX = data.n_img.width - p.texX - 1;
	p.y = 0;
	while (p.y < SCREEN_H)
	{
		if (p.y < start)
			ft_pixel(&data.screen_img, caster.x, p.y, 0x0000DD);
		else if (p.y > end)
			ft_pixel(&data.screen_img, caster.x, p.y, 0xC19A6B);
		else
			draw_dispatch(caster, data, p);
		p.y++;
	}
}

void	draw(t_rayCast caster, t_data data)
{
	int	height;
	int	start;
	int	end;

	height = (int)(SCREEN_H / caster.walldist);
	start = (SCREEN_H / 2 - (height / 2));
	end = (SCREEN_H / 2 + (height / 2));
	drawline(caster, start, end, data);
}
