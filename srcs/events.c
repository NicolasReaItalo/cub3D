/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:28:59 by nrea              #+#    #+#             */
/*   Updated: 2024/05/29 13:43:34 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_keyrelease(int key, t_data *data)
{
	if (key == XK_Left)
		data->keypress[4] = 0;
	if (key == XK_Right)
		data->keypress[5] = 0;
	if (key == XK_a)
		data->keypress[2] = 0;
	if (key == XK_w)
		data->keypress[0] = 0;
	if (key == XK_s)
		data->keypress[1] = 0;
	if (key == XK_d)
		data->keypress[3] = 0;
	return (0);
}

int	ft_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_destroy_window(data);
	if (key == XK_Left)
		data->keypress[4] = 1;
	if (key == XK_Right)
		data->keypress[5] = 1;
	if (key == XK_a)
		data->keypress[2] = 1;
	if (key == XK_w)
		data->keypress[0] = 1;
	if (key == XK_s)
		data->keypress[1] = 1;
	if (key == XK_d)
		data->keypress[3] = 1;
	return (0);
}
