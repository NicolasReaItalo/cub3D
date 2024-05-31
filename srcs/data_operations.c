/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:07:34 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 16:09:17 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_tex_path(t_data *data)
{
	free(data->n_img.path);
	free(data->s_img.path);
	free(data->w_img.path);
	free(data->e_img.path);
}

static void	init_data_const(t_data *data)
{
	data->c_color = DEFAULT_CEILING;
	data->f_color = DEFAULT_FLOOR;
	data->pos.x = -1;
	data->pos.y = -1;
	data->dir.x = -1;
	data->dir.y = -1;
	data->map_w = 0;
	data->map_h = 0;
	data->map = NULL;
}

int	init_data(t_data *data)
{
	init_data_const(data);
	data->n_img.path = ft_strdup(DEFAULT_NORTH_PATH);
	if (!data->n_img.path)
		return (ERR_INTERNAL);
	data->s_img.path = ft_strdup(DEFAULT_SOUTH_PATH);
	if (!data->s_img.path)
		return (free(data->n_img.path),ERR_INTERNAL);
	data->e_img.path = ft_strdup(DEFAULT_EAST_PATH);
	if (!data->e_img.path)
		return (free(data->n_img.path),free(data->s_img.path),ERR_INTERNAL);
	data->w_img.path = ft_strdup(DEFAULT_WEST_PATH);
	if (!data->w_img.path)
	{
		free(data->e_img.path);
		return (free(data->n_img.path),free(data->s_img.path),ERR_INTERNAL);
	}
	return (SUCCESS);
}
