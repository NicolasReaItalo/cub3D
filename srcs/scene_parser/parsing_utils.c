/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:01:10 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 10:59:07 by nrea             ###   ########.fr       */
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

int	check_valid_colors(char *s1, char *s2, char *s3)
{
	if (!is_all_digits(s1))
		return (0);
	if (!is_all_digits(s2))
		return (0);
	if (!is_all_digits(s3))
		return (0);
	return (1);
}

/*strips spaces before and after the word*/
char	*strip(char *s)
{
	char	*start;
	int		end_index;

	end_index = ft_strlen(s);
	if (!*s || !end_index)
		return ("X");
	start = s;
	while (*start == ' ')
		start++;
	end_index--;
	while (end_index >= 0 && s[end_index] == ' ')
	{
		s[end_index] = '\0';
		end_index--;
	}
	return (start);
}
