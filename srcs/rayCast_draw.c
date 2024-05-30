/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:36:26 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/30 12:00:35 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	draw_north(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (int)(((double)(p.y - p.start) / (double)(p.end - p.start)) * data.n_img.height);
	tex_pixel_pos = (y_tex * data.n_img.img.line_len)
		+ (p.texX * (data.n_img.img.bpp >> 3));
	img_pixel_pos = (p.y * data.screen_img.line_len)
		+ (caster.x * data.screen_img.bpp >> 3);
	i = 0;
	while (i++ < 8)
		data.screen_img.addr[img_pixel_pos + i]
			= data.n_img.img.addr[tex_pixel_pos + i];
}

static void	draw_south(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (int)(((double)(p.y - p.start) / (double)(p.end - p.start))
			* data.s_img.height);
	tex_pixel_pos = (y_tex * data.s_img.img.line_len)
		+ (p.texX * (data.s_img.img.bpp >> 3));
	img_pixel_pos = (p.y * data.screen_img.line_len)
		+ (caster.x * data.screen_img.bpp >> 3);
	i = 0;
	while (i++ < 8)
		data.screen_img.addr[img_pixel_pos + i]
			= data.s_img.img.addr[tex_pixel_pos + i];
}

static void	draw_east(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (int)(((double)(p.y - p.start) / (double)(p.end - p.start))
			* data.e_img.height);
	tex_pixel_pos = (y_tex * data.e_img.img.line_len)
		+ (p.texX * (data.e_img.img.bpp >> 3));
	img_pixel_pos = (p.y * data.screen_img.line_len)
		+ (caster.x * data.screen_img.bpp >> 3);
	i = 0;
	while (i++ < 8)
		data.screen_img.addr[img_pixel_pos + i]
			= data.e_img.img.addr[tex_pixel_pos + i];
}

static void	draw_west(t_rayCast caster, t_data data, t_draw_p p)
{
	int	y_tex;
	int	tex_pixel_pos;
	int	img_pixel_pos;
	int	i;

	y_tex = (int)(((double)(p.y - p.start) / (double)(p.end - p.start))
			* data.w_img.height);
	tex_pixel_pos = (y_tex * data.w_img.img.line_len)
		+ (p.texX * (data.w_img.img.bpp >> 3));
	img_pixel_pos = (p.y * data.screen_img.line_len)
		+ (caster.x * data.screen_img.bpp >> 3);
	i = 0;
	while (i++ < 8)
		data.screen_img.addr[img_pixel_pos + i]
			= data.w_img.img.addr[tex_pixel_pos + i];
}

void	draw_dispatch(t_rayCast caster, t_data data, t_draw_p p)
{
	if (caster.side == 0)
		draw_north(caster, data, p);
	else if (caster.side == 1)
		draw_south(caster, data, p);
	else if (caster.side == 2)
		draw_east(caster, data, p);
	else
		draw_west(caster, data, p);
}
