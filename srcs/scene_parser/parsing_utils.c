/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:01:10 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 15:43:30 by nrea             ###   ########.fr       */
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

/*checks if the character c belongs to a given character set*/
int	isinset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_all_digits(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	check_if_all_digits(char *s1, char *s2, char *s3)
{
	if (!is_all_digits(s1))
		return (0);
	if (!is_all_digits(s2))
		return (0);
	if (!is_all_digits(s3))
		return (0);
	return (1);
}
