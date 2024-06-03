/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:11:41 by nrea              #+#    #+#             */
/*   Updated: 2024/06/03 10:28:36 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_vector2d	ft_apply2dmat(t_vector2d point, double m[2][2])
{
	t_vector2d	p;

	p.x = point.x * m[0][0] + point.y * m[0][1];
	p.y = point.x * m[1][0] + point.y * m[1][1];
	return (p);
}
