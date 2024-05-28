/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:55:45 by nrea              #+#    #+#             */
/*   Updated: 2024/05/27 12:57:56 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Compute the absolute differnce between two points in x and y axis
not very clear thank you the norm*/
t_vector2d	ft_compute_abs_diff(t_vector2d p0, t_vector2d p1)
{
	t_vector2d	d;

	d.x = ft_abs_int(p1.x - p0.x);
	d.y = ft_abs_int(p1.y - p0.y);
	return (d);
}

/*Returns the nb of occurence of a NULL terminated splitted array*/
int	ft_split_size(char **splitted)
{
	int	size;

	if (!splitted)
		return (0);
	size = 0;
	while (splitted[size])
	{
		if (!(ft_isdigit(splitted[size][0]) || splitted[size][0] == '-'))
			break ;
		size++;
	}
	return (size);
}

/*Free the 2D arry grid*/
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
