/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:26:14 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 12:23:14 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*returns the retcode*/
static int	look_for_tex(char *content, t_data *data, int *match_found)
{
	if (!ft_strncmp(content, "NO", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->s_img.path));
	}
	else if (!ft_strncmp(content, "SO", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->n_img.path));
	}
	else if (!ft_strncmp(content, "WE", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->e_img.path));
	}
	else if (!ft_strncmp(content, "EA", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->w_img.path));
	}
	return (0);
}

static int	look_for_col(char *content, t_data *data, int *match_found)
{
	if (content[0] == 'F')
	{
		*match_found = 1;
		return (get_color_info(&data->f_color, content));
	}
	else if (content[0] == 'C')
	{
		*match_found = 1;
		return (get_color_info(&data->c_color, content));
	}
	return (0);
}

static int	allocate_map(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(data->map_h * sizeof(int *));
	if (!data->map)
		return (ERR_INTERNAL);
	while (i < data->map_h)
	{
		data->map[i] = ft_calloc(data->map_w, sizeof(int));
		if (!data->map[i])
			return (ERR_INTERNAL);
		i++;
	}
	return (SUCCESS);
}

static int	parse_map(t_line *scene, t_data *data)
{
	int	retcode;

	retcode = 0;
	retcode = find_map_dimensions(scene, &data->map_w, &data->map_h);
	if (retcode || data->map_w == 0 || data->map_h == 0)
		return (retcode);
	if (allocate_map(data))
		return (ERR_INTERNAL);
	retcode = 0;
	retcode = populate_map(scene, data);
	if (retcode)
		return (retcode);
	if (is_map_closed(data))
		return (ERR_MAP_NOT_CLOSED);
	return (SUCCESS);
}

int	parse_scene(t_line **scene, t_data *data)
{
	t_line	*s;
	int		ret_code;
	int		match_found;

	ret_code = 0;
	s = *scene;
	while (s)
	{
		if (ft_strlen(s->content))
		{
			match_found = 0;
			ret_code = look_for_tex(s->content, data, &match_found);
			if (!match_found)
				ret_code = look_for_col(s->content, data, &match_found);
			if (!match_found && isinset(s->content[0], " 01NSWE"))
				return (parse_map(s, data));
			else if (!match_found)
				ret_code = ERR_CHAR;
			if (ret_code)
				return (ret_code);
		}
		s = s->next;
	}
	return (0);
}
