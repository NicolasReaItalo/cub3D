/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:36:26 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/31 16:09:54 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	_draw_north(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (p.y - p.start) * p.nstep;
	tex_pixel_pos = (y_tex * data.n_img.img.line_len) + p.texn;
	img_pixel_pos = (p.y * data.screen_img.line_len) + caster.x_shift;
	i = -1;
	while (i++ < 7)
		data.screen_img.addr[img_pixel_pos + i]
			= data.n_img.img.addr[tex_pixel_pos + i];
}

static void	_draw_south(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (p.y - p.start) * p.sstep;
	tex_pixel_pos = (y_tex * data.s_img.img.line_len) + p.texs;
	img_pixel_pos = (p.y * data.screen_img.line_len) + caster.x_shift;
	i = -1;
	while (i++ < 7)
		data.screen_img.addr[img_pixel_pos + i]
			= data.s_img.img.addr[tex_pixel_pos + i];
}

static void	_draw_east(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (p.y - p.start) * p.estep;
	tex_pixel_pos = (y_tex * data.e_img.img.line_len) + p.texe;
	img_pixel_pos = (p.y * data.screen_img.line_len)
		+ caster.x_shift;
	i = -1;
	while (i++ < 7)
		data.screen_img.addr[img_pixel_pos + i]
			= data.e_img.img.addr[tex_pixel_pos + i];
}

static void	_draw_west(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (p.y - p.start) * p.wstep;
	tex_pixel_pos = (y_tex * data.w_img.img.line_len) + p.texw;
	img_pixel_pos = (p.y * data.screen_img.line_len) + caster.x_shift;
	i = -1;
	while (i++ < 7)
		data.screen_img.addr[img_pixel_pos + i]
			= data.w_img.img.addr[tex_pixel_pos + i];
}

void	draw_dispatch(t_rayCast caster, t_data data, t_draw_p p)
{
	if (caster.side == 0)
		_draw_north(caster, data, p);
	else if (caster.side == 2)
		_draw_south(caster, data, p);
	else if (caster.side == 3)
		_draw_east(caster, data, p);
	else
		_draw_west(caster, data, p);
}
