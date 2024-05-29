/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:36:26 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/29 13:38:31 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	drawline(t_rayCast caster, int start, int end, t_data data)
{
	int	y;

	y = 0;
	while (y < SCREEN_H)
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
	int	end;

	height = (int)(SCREEN_H / caster.walldist);
	start = fmax(SCREEN_H / 2 - (height / 2), 0);
	end = fmin(SCREEN_H / 2 + (height / 2), SCREEN_H);
	drawline(caster, start, end, data);
}
