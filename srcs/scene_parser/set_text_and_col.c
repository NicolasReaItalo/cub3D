/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_text_and_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:54:30 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 15:54:43 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*parse the char *s to find color infos and set the pointer color*/
int	get_color_info(int	*color, char *s)
{
	char	**splitted;
	int		r;
	int		g;
	int		b;

	s += 2;
	if (!*s)
		return (ERR_TEX);
	while (*s == ' ')
		s++;
	splitted = ft_split(s, ',');
	if (!splitted)
		return (ERR_INTERNAL);
	if (ft_split_size(splitted) != 3)
		return (ft_free_split(splitted), ERR_COLOR);
	if (!check_if_all_digits(splitted[0], splitted[1], splitted[2]))
		return (ft_free_split(splitted), ERR_COLOR);
	r = ft_atoi(splitted[0]);
	g = ft_atoi(splitted[1]);
	b = ft_atoi(splitted[2]);
	if (r > 255 || g > 255 || b > 255)
		return (ft_free_split(splitted), ERR_COLOR);
	*color = r << 16 | g << 8 | b;
	ft_free_split(splitted);
	return (SUCCESS);
}

/*get the path to the texture form the content and set the pointer*/
int	get_texture_path(char *content, char **path)
{
	free(*path);
	content += 2;
	if (!*content)
		return (ERR_TEX);
	while (*content == ' ')
		content++;
	*path = ft_strdup(content);
	if (!*path)
		return (ERR_INTERNAL);
	return (SUCCESS);
}
