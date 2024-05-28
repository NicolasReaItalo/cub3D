/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:28:59 by nrea              #+#    #+#             */
/*   Updated: 2024/05/27 12:57:56 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_destroy_window(data);
	else if (key == XK_Left)
		printf("Left key pressed\n");
	else if (key == XK_Right)
		printf("Right key pressed\n");
	else if (key == XK_a)
		printf("A key pressed\n");
	else if (key == XK_w)
		printf("W key pressed\n");
	else if (key == XK_s)
		printf("S key pressed\n");
	else if (key == XK_d)
		printf("D key pressed\n");
	return (0);
}
