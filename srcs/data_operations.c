/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:07:34 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 11:58:15 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_tex_path(t_data *data)
{
	if (data->n_img.path)
		free(data->n_img.path);
	if (data->s_img.path)
		free(data->s_img.path);
	if (data->w_img.path)
		free(data->w_img.path);
	if (data->e_img.path)
		free(data->e_img.path);
}

static void	init_data_const(t_data *data)
{
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
	data->n_img.path = NULL;
	data->s_img.path = NULL;
	data->e_img.path = NULL;
	data->w_img.path = NULL;
	data->c_color = -1;
	data->f_color = -1;
}

static int	are_all_set(t_data *data)
{
	if (data->c_color == -1 || data->f_color == -1)
		return (0);
	if (data->n_img.path == NULL)
		return (0);
	if (data->s_img.path == NULL)
		return (0);
	if (data->e_img.path == NULL)
		return (0);
	if (data->w_img.path == NULL)
		return (0);
	return (1);
}

int	parser_init(int argc, char **argv, t_data *data)
{
	t_line	*scene;
	int		r;

	r = 0;
	if (argc != 2)
		return (ERR_USAGE);
	init_data_const(data);
	r = load_scene(argv[1], &scene);
	if (r)
		return (r);
	r = parse_scene(&scene, data);
	free_scene(&scene);
	if (r)
		return (free_map(data->map, data->map_h), free_tex_path(data), r);
	if (data->map == NULL)
		return (free_tex_path(data), ERR_NO_MAP);
	if (!are_all_set(data))
	{
		free_tex_path(data);
		free_map(data->map, data->map_h);
		return (ERR_NOT_ALL_SET);
	}
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
	data->map_img.mlx_img = NULL;
}
