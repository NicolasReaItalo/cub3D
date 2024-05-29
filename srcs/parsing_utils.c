/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:01:10 by nrea              #+#    #+#             */
/*   Updated: 2024/05/29 13:54:31 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*checks if the filename s ends with .cub*/
int	ft_check_extension(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	if (i < 5)
		return (0);
	i -= 4;
	if (!strncmp(s + i, ".cub", 4))
		return (1);
	return (0);
}
