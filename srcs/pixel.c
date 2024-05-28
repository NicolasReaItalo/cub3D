/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:43:03 by nrea              #+#    #+#             */
/*   Updated: 2024/05/27 12:57:56 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Color the selected pixel on the image*/
void	ft_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
