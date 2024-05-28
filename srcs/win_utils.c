/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:59:29 by nrea              #+#    #+#             */
/*   Updated: 2024/05/27 12:57:56 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Function called in case of closing window signal or ESC button pressed*/
void	ft_end_safe(t_data *data)
{
	t_img	*img;

	img = &(data->img);
	if (img->mlx_img)
		mlx_destroy_image(data->mlx_ptr, img->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->win_ptr = NULL;
}

int	ft_destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_end_safe(data);
	exit (0);
}

void	ft_print_cmd(void)
{
	printf("\033[1;34mWELCOME TO CUBE3D\033[0m");
	printf("\n\033[0;32mROTATE CAMERA:\033[0m [←][→]\n");
	printf("\033[0;32mMOVE:\033[0m [A][W][S][D]\n");
}
