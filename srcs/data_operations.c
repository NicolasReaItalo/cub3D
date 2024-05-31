/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:07:34 by nrea              #+#    #+#             */
/*   Updated: 2024/05/31 13:06:49 by qgiraux          ###   ########.fr       */
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
	data->n_img.img.mlx_img = NULL;
	data->s_img.img.mlx_img = NULL;
	data->e_img.img.mlx_img = NULL;
	data->w_img.img.mlx_img = NULL;
	data->map = NULL;
	data->keypress[0] = 0;
	data->keypress[1] = 0;
	data->keypress[2] = 0;
	data->keypress[3] = 0;
	data->keypress[4] = 0;
	data->keypress[5] = 0;
}

int	init_data(t_data *data)
{
	init_data_const(data);
	data->n_img.path = ft_strdup(DEFAULT_NORTH_PATH);
	if (!data->n_img.path)
		return (ERR_INTERNAL);
	data->s_img.path = ft_strdup(DEFAULT_SOUTH_PATH);
	if (!data->s_img.path)
		return (free(data->n_img.path), ERR_INTERNAL);
	data->e_img.path = ft_strdup(DEFAULT_EAST_PATH);
	if (!data->e_img.path)
		return (free(data->n_img.path), free(data->s_img.path), ERR_INTERNAL);
	data->w_img.path = ft_strdup(DEFAULT_WEST_PATH);
	if (!data->w_img.path)
	{
		free(data->e_img.path);
		return (free(data->n_img.path), free(data->s_img.path), ERR_INTERNAL);
	}
	return (SUCCESS);
}

int	parser_init(int argc, char **argv, t_data *data)
{
	t_line	*scene;
	int		r;

	r = 0;
	if (argc != 2)
		return (ERR_USAGE);
	r = init_data(data);
	if (r)
		return (r);
	r = load_scene(argv[1], &scene);
	if (r)
		return (free_tex_path(data), r);
	r = parse_scene(&scene, data);
	if (r)
	{
		free_scene(&scene);
		free_map(data->map, data->map_h);
		free_tex_path(data);
		return (r);
	}
	free_scene(&scene);
	if (data->map == NULL)
		return (free_tex_path(data), ERR_NO_MAP);
	init_cam(data);
	return (SUCCESS);
}

void	init_cam(t_data *data)
{
	double	mat[2][2];

	mat[0][0] = 0;
	mat[0][1] = 0.66;
	mat[1][0] = -0.66;
	mat[1][1] = 0;
	data->cam = ft_apply2dmat(data->dir, mat);
}
