/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:55:45 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 10:48:31 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*Returns the nb of occurence of a NULL terminated splitted array*/
int	ft_split_size(char **splitted)
{
	int	size;

	if (!splitted)
		return (0);
	size = 0;
	while (splitted[size])
		size++;
	return (size);
}

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

int	free_map(int **map, int map_h)
{
	int	i;

	if (NULL == map || !map || !*map)
		return (0);
	i = 0;
	while (i < map_h)
	{
		if (map[i])
			free(map[i]);
		else
			break ;
		i++;
	}
	if (map)
		free(map);
	map = NULL;
	return (0);
}
