/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:45:08 by qgiraux           #+#    #+#             */
/*   Updated: 2024/05/31 11:38:26 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	_set_nimg(t_data *data)
{
	data->n_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->n_img.path, &data->n_img.width, &data->n_img.height);
	if (!data->n_img.img.mlx_img)
		return (0);
	data->n_img.img.addr = mlx_get_data_addr(data->n_img.img.mlx_img,
			&data->n_img.img.bpp, &data->n_img.img.line_len,
			&data->n_img.img.endian);
	return (1);
}

static int	_set_simg(t_data *data)
{
	data->s_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->s_img.path, &data->s_img.width, &data->s_img.height);
	if (!data->s_img.img.mlx_img)
		return (0);
	data->s_img.img.addr = mlx_get_data_addr(data->s_img.img.mlx_img,
			&data->s_img.img.bpp, &data->s_img.img.line_len,
			&data->s_img.img.endian);
	return (1);
}

static int	_set_eimg(t_data *data)
{
	data->e_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->e_img.path, &data->e_img.width, &data->e_img.height);
	if (!data->e_img.img.mlx_img)
		return (0);
	data->e_img.img.addr = mlx_get_data_addr(data->e_img.img.mlx_img,
			&data->e_img.img.bpp, &data->e_img.img.line_len,
			&data->e_img.img.endian);
	return (1);
}

static int	_set_wimg(t_data *data)
{
	data->w_img.img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->w_img.path, &data->w_img.width,
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
	if (!_set_nimg(data))
		return (ERR_NOTEX);
	if (!_set_simg(data))
		return (ERR_NOTEX);
	if (!_set_eimg(data))
		return (ERR_NOTEX);
	if (!_set_wimg(data))
		return (ERR_NOTEX);
	return (0);
}
