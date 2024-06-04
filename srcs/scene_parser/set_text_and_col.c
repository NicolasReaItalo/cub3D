/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_text_and_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:54:30 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 10:58:50 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*parse the char *s to find color infos and set the pointer color*/
int	get_color_info(int	*color, char *s)
{
	char	**t;
	int		r;
	int		g;
	int		b;

	s += 1;
	if (!*s)
		return (ERR_COLOR);
	if (*color != -1)
		return (ERR_COL_ALREADY_SET);
	t = ft_split(s, ',');
	if (!t)
		return (ERR_INTERNAL);
	if (ft_split_size(t) != 3)
		return (ft_free_split(t), ERR_COLOR);
	if (!check_valid_colors(strip(t[0]), strip(t[1]), strip(t[2])))
		return (ft_free_split(t), ERR_COLOR);
	r = ft_atoi(t[0]);
	g = ft_atoi(t[1]);
	b = ft_atoi(t[2]);
	if (r > 255 || g > 255 || b > 255)
		return (ft_free_split(t), ERR_COLOR);
	*color = r << 16 | g << 8 | b;
	ft_free_split(t);
	return (SUCCESS);
}

/*get the path to the texture form the content and set the pointer*/
int	get_texture_path(char *content, char **path)
{
	if (*path != NULL)
		return (ERR_TEX_ALREADY_SET);
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
