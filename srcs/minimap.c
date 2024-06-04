/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:49:19 by qgiraux           #+#    #+#             */
/*   Updated: 2024/06/04 10:48:14 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static void	_draw_square(int x, int y, int color, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->mmap_size)
	{
		while (j < data->mmap_size)
		{
			_img_pix_put(&data->map_img, y + i, x + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

static void	_draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (x < data->map_w)
	{
		while (y < data->map_h)
		{
			if (data->map[y][x] == 0)
				_draw_square(j, i, 0xFFFFFF, data);
			if ((int)(data->pos.x) == y && (int)(data->pos.y) == x)
				_draw_square(j, i, 0x00FF, data);
			j = j + data->mmap_size;
			y++;
		}
		j = 0;
		y = 0;
		i = i + data->mmap_size;
		x++;
	}
}

int	ft_minimap(t_data *data)
{
	data->mmap_size = (SCALE * SCREEN_H) / fmax(data->map_w, data->map_h);
	if (!data->map_img.mlx_img)
		data->map_img.mlx_img = mlx_new_image(data->mlx_ptr,
				data->mmap_size * data->map_w, data->mmap_size * data->map_h);
	if (!data->map_img.mlx_img)
		return (0);
	data->map_img.addr = mlx_get_data_addr(data->map_img.mlx_img,
			&data->map_img.bpp, &data->map_img.line_len, &data->map_img.endian);
	if (!data->map_img.addr)
		return (0);
	_draw_map(data);
	return (1);
}
