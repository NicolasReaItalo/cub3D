/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:11:41 by nrea              #+#    #+#             */
/*   Updated: 2024/05/29 13:54:46 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*return 1 if value > 0 - 1 otherwise or 0 if value is 0*/
int	ft_sign(int value)
{
	if (value > 0)
		return (1);
	else if (value < 0)
		return (-1);
	return (0);
}

/*returns the absolute value of an int
if the value is INT MIN returns INT_MAX*/
int	ft_abs_int(int value)
{
	if (value >= 0)
		return (value);
	if (value == INT_MIN)
		value++;
	return (-value);
}

t_vector2d	ft_apply2dmat(t_vector2d point, double m[2][2])
{
	t_vector2d	p;

	p.x = point.x * m[0][0] + point.y * m[0][1];
	p.y = point.x * m[1][0] + point.y * m[1][1];
	return (p);
}

/*Multiply a vector(2) Point2D by a scalar          */
void	ft_scalar_mul(t_vector2d *p, double scalar)
{
	if (!p)
		return ;
	p->x *= scalar;
	p->y *= scalar;
}
