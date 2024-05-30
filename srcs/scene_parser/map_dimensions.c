/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:59:01 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 15:59:17 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	find_longest_row(t_line *scene)
{
	t_line	*s;
	int		max;
	int		i;

	max = 0;
	s = scene;
	while (s)
	{
		if (!ft_strlen(scene->content))
			return (-1);
		i = 0;
		while (s->content[i])
		{
			if (!isinset(s->content[i], " 01NSWE"))
				return (-2);
			i++;
		}
		if (i > max)
			max = i;
		s = s->next;
	}
	return (max);
}

/*parses the scene to caculate the dimensions of the grid array*/
int	find_map_dimensions(t_line *scene, int *w, int *h)
{
	t_line	*s;

	*w = find_longest_row(scene);
	if (*w == -1)
		return (ERR_EMPTY);
	else if (*w == -2)
		return (ERR_CHAR);
	*h = 0;
	s = scene;
	while (s)
	{
		*h += 1;
		s = s->next;
	}
	if (*w < 3 || *h < 3)
		return (ERR_MAP_DIMENSIONS);
	return (SUCCESS);
}
