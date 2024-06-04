/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:18 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 12:49:00 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*The function called by the loop at each frame
refresh the screen / draw the grid / show menu */
int	ft_render(t_data *data)
{
	void	*mlx;
	void	*win;
	void	*screen_img;
	int		col;

	screen_img = data->screen_img.mlx_img;
	col = 0xFF00FF;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	if (data->win_ptr == NULL || data->mlx_ptr == NULL)
		return (1);
	ft_keyact(data);
	ft_cast_angles(*data);
	ft_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, screen_img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->map_img.mlx_img, SCREEN_W - data->mmap_size * data->map_w,
		SCREEN_H - data->mmap_size * data->map_h);
	return (0);
}

void	ft_set_hooks(t_data *data)
{
	int	y;

	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &data->mousex, &y);
	mlx_loop_hook(data->mlx_ptr, &ft_render, data);
	mlx_hook(data->win_ptr, 17, 1L << 2, &ft_destroy_window, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &ft_keyrelease, data);
}

int	ft_set_img(t_data *data)
{
	int		*e;
	int		*l;

	data->screen_img.mlx_img = mlx_new_image(data->mlx_ptr, SCREEN_W, SCREEN_H);
	if (!data->screen_img.mlx_img)
		return (0);
	e = &data->screen_img.endian;
	l = &data->screen_img.line_len;
	data->screen_img.addr = mlx_get_data_addr(data->screen_img.mlx_img,
			&data->screen_img.bpp, l, e);
	if (!data->screen_img.addr)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		r;

	r = parser_init(argc, argv, &data);
	if (r != 0)
		return (error_handler(r));
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_exit_mlx_init(&data);
	if (ERR_NOTEX == ft_set_walls(&data))
	{
		free_walls(&data);
		free_tex_path(&data);
		mlx_destroy_display(data.mlx_ptr);
		free_map(data.map, data.map_h);
		return (free(data.mlx_ptr), error_handler(ERR_NOTEX));
	}
	free_tex_path(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, SCREEN_W, SCREEN_H, "cub3D");
	if (data.win_ptr == NULL)
		ft_exit_mlx_window(&data);
	if (!ft_set_img(&data))
		ft_destroy_window(&data);
	ft_set_hooks(&data);
	mlx_loop(data.mlx_ptr);
}
