/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:47:30 by nrea              #+#    #+#             */
/*   Updated: 2024/05/31 16:23:37 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_posdir(t_data *data, char c, int w, int h)
{
	if (data->pos.y >= 0 || data->pos.x >= 0)
		return (ERR_POS_ALREADY_SET);
	data->pos.y = w + 0.5;
	data->pos.x = h + 0.5;
	if (c == 'N')
	{
		data->dir.x = -1;
		data->dir.y = 0;
	}
	else if (c == 'S')
	{
		data->dir.x = 1;
		data->dir.y = 0;
	}
	else if (c == 'W')
	{
		data->dir.x = 0;
		data->dir.y = -1;
	}
	else if (c == 'E')
	{
		data->dir.x = 0;
		data->dir.y = 1;
	}
	return (SUCCESS);
}

static void	set_content(t_data *data, int h, int w, char c)
{
	if (c == '0')
		data->map[h][w] = 0;
	if (c == '1')
		data->map[h][w] = 1;
}

static char	*increment_content(char *content)
{
	if (*content)
		return (content + 1);
	else
		return (content);
}

static int	populate_line(t_line *s, t_data *data, int h)
{
	int		w;
	char	*content;
	int		ret;

	w = 0;
	ret = 0;
	content = s->content;
	while (w < data->map_w)
	{
		if (!*content || *content == ' ')
			data->map[h][w] = 9;
		else if (*content == '0' || *content == '1')
			set_content(data, h, w, *content);
		else if (isinset(*content, "NSEW"))
		{
			ret = get_posdir(data, *content, w, h);
			if (ret)
				return (ret);
		}
		else
			return (ERR_CHAR);
		content = increment_content(content);
		w++;
	}
	return (SUCCESS);
}

int	populate_map(t_line *scene, t_data *data)
{
	t_line	*s;
	int		h;
	int		ret;

	s = scene;
	h = 0;
	ret = 0;
	while (h < data->map_h)
	{
		if (!ft_strlen(s->content))
			return (ERR_EMPTY);
		ret = populate_line(s, data, h);
		if (ret)
			return (ret);
		h++;
		s = s->next;
	}
	if (data->pos.y < 0 || data->pos.x < 0)
		return (ERR_POS_NOT_SET);
	return (SUCCESS);
}
