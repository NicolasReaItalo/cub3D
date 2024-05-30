/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:55:45 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 15:33:17 by nrea             ###   ########.fr       */
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

	if (!map)
		return (0);
	i = 0;
	while (i < map_h)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
