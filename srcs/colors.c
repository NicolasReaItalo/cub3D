/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:17:54 by nrea              #+#    #+#             */
/*   Updated: 2024/05/27 12:57:56 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*linear interpolation between 2 colors. factor must be set between 0
(full color 1) and 1 (full color 2)*/
int	ft_lerp(int c1, int c2, double f)
{
	int	r;
	int	g;
	int	b;

	if (f > 1)
		f = 1;
	b = (int)(c1 & (0xFF)) + ((c2 & (0xFF)) - (c1 & (0xFF))) * f;
	g = (int)(c1 &(0xFF00)) + ((c2 & (0xFF00)) - (c1 & (0xFF00))) * f;
	r = (int)(c1 & (0xFF0000)) + ((c2 & (0xFF0000)) - (c1 & (0xFF0000))) * f;
	r = r & 0xFF0000;
	g = g & 0xFF00;
	b = b & 0xFF;
	return (r | g | b);
}

int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r | g | b);
}
