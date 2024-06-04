/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:02:19 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 12:07:30 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_exit_mlx_init(t_data *data)
{
	(void)data;
	write(2, "Minilibx initialisation error\n", 31);
	exit (1);
}

void	ft_exit_mlx_window(t_data *data)
{
	free(data->mlx_ptr);
	write(2, "Error during the windows initialisation\n", 41);
	exit (1);
}
