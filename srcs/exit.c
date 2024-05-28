/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:02:19 by nrea              #+#    #+#             */
/*   Updated: 2024/05/27 12:57:56 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_exit_mlx_init(t_data *data)
{
	(void)	data;
	perror("Minilibx initialisation error");
	exit (1);
}

void	ft_exit_mlx_window(t_data *data)
{
	free(data->mlx_ptr);
	perror("Error during the windows initialisation");
	exit (1);
}
