/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:59:29 by nrea              #+#    #+#             */
/*   Updated: 2024/06/03 16:06:12 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Function called in case of closing window signal or ESC button pressed*/
void	ft_end_safe(t_data *data)
{
	t_img	*screen_img;

	screen_img = &(data->screen_img);
	if (screen_img->mlx_img)
		mlx_destroy_image(data->mlx_ptr, screen_img->mlx_img);
	if (data->map_img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->map_img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data->map, data->map_h);
	data->win_ptr = NULL;
}

void	free_walls(t_data *data)
{
	if (data->n_img.img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->n_img.img.mlx_img);
	if (data->s_img.img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->s_img.img.mlx_img);
	if (data->e_img.img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->e_img.img.mlx_img);
	if (data->w_img.img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->w_img.img.mlx_img);
}

int	ft_destroy_window(t_data *data)
{
	free_walls(data);
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_end_safe(data);
	exit (0);
}
