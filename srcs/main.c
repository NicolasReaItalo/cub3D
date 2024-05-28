/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:49:18 by nrea              #+#    #+#             */
/*   Updated: 2024/05/28 10:42:42 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*fill all the img with a color gradient*/
void	ft_refresh(t_img *img, int color)
{
	int		r;
	int		c;
	double	factor;

	factor = (double) 1 / SCREEN_HEIGHT;
	r = 0;
	while (r < SCREEN_HEIGHT)
	{
		c = 0;
		while (c < SCREEN_WIDTH)
		{
			ft_pixel(img, c, r, ft_lerp(color, 0x0A, factor));
			c++;
		}
		r++;
		factor += 0.00125;
	}
}

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
	ft_refresh(&data->screen_img, 0x002255);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, screen_img, 0, 0);
	return (0);
}

void	ft_set_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_render, data);
	mlx_hook(data->win_ptr, 17, 1L << 2, &ft_destroy_window, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_keypress, data);
}

int	ft_set_img(t_data *data)
{
	int		*e;
	int		*l;

	data->screen_img.mlx_img = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!data->screen_img.mlx_img)
		return (0);
	e = &data->screen_img.endian;
	l = &data->screen_img.line_len;
	data->screen_img.addr = mlx_get_data_addr(data->screen_img.mlx_img, &data->screen_img.bpp, l, e);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	(void)	argc;
	(void)	argv;


	data.map = NULL;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_exit_mlx_init(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (data.win_ptr == NULL)
		ft_exit_mlx_window(&data);
	if (!ft_set_img(&data))
		ft_destroy_window(&data);
	ft_set_hooks(&data);
	ft_print_cmd();
	mlx_loop(data.mlx_ptr);
}
