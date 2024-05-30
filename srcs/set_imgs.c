/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:45:08 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/30 11:42:18 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_set_nimg(t_data *data)
{
	data->n_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wallS.xpm", &data->n_img.width, &data->n_img.height);
	if (!data->n_img.img.mlx_img)
		return (0);
	data->n_img.img.addr = mlx_get_data_addr(data->n_img.img.mlx_img,
			&data->n_img.img.bpp, &data->n_img.img.line_len,
			&data->n_img.img.endian);
	return (1);
}

int	ft_set_simg(t_data *data)
{
	data->s_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/02camino.xpm", &data->s_img.width, &data->s_img.height);
	if (!data->s_img.img.mlx_img)
		return (0);
	data->s_img.img.addr = mlx_get_data_addr(data->s_img.img.mlx_img,
			&data->s_img.img.bpp, &data->s_img.img.line_len,
			&data->s_img.img.endian);
	return (1);
}

int	ft_set_eimg(t_data *data)
{
	data->e_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/mosaic1.xpm", &data->e_img.width, &data->e_img.height);
	if (!data->e_img.img.mlx_img)
		return (0);
	data->e_img.img.addr = mlx_get_data_addr(data->e_img.img.mlx_img,
			&data->e_img.img.bpp, &data->e_img.img.line_len,
			&data->e_img.img.endian);
	return (1);
}

int	ft_set_wimg(t_data *data)
{
	data->w_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall_256x256_1.xpm", &data->w_img.width,
			&data->w_img.height);
	if (!data->w_img.img.mlx_img)
		return (0);
	data->w_img.img.addr = mlx_get_data_addr(data->w_img.img.mlx_img,
			&data->w_img.img.bpp, &data->w_img.img.line_len,
			&data->w_img.img.endian);
	return (1);
}

int	ft_set_walls(t_data *data)
{
	if (!ft_set_nimg(data))
		return (1);
	if (!ft_set_simg(data))
		return (1);
	if (!ft_set_eimg(data))
		return (1);
	if (!ft_set_wimg(data))
		return (1);
	return (0);
}
