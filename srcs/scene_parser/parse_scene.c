/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:26:14 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 14:42:25 by nrea             ###   ########.fr       */
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

/*Return 0 in case of success*/
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
	if (!is_all_digits(splitted[0]) || !is_all_digits(splitted[1]) || !is_all_digits(splitted[2]))
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

/*get the path to the texture form the content*/
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

/*returns the retcode*/
static int	look_for_tex(char *content, t_data *data, int *match_found)
{
	if (!ft_strncmp(content, "NO", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->n_img.path));
	}
	else if (!ft_strncmp(content, "SO", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->s_img.path));
	}
	else if (!ft_strncmp(content, "WE", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->w_img.path));
	}
	else if (!ft_strncmp(content, "EA", 2))
	{
		*match_found = 1;
		return (get_texture_path(content, &data->e_img.path));
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

int	allocate_map(t_data *data)
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
			return (free_map(data->map, i), ERR_INTERNAL);
		i++;
	}
	return (SUCCESS);
}

int	get_posdir(t_data *data, char c, int w, int h)
{
	if (data->pos.y >= 0 || data->pos.x >= 0)
		return (ERR_POS_ALREADY_SET);
	data->pos.x = w;
	data->pos.y = h;
	if (c == 'N')
	{
		data->dir.x = 0;
		data->dir.y = -1;
	}
	else if (c == 'S')
	{
		data->dir.x = 0;
		data->dir.y = 1;
	}
	else if (c == 'W')
	{
		data->dir.x = -1;
		data->dir.y = 0;
	}
	else if (c == 'E')
	{
		data->dir.x = 1;
		data->dir.y = 0;
	}
	return (SUCCESS);
}

int	populate_line(t_line *s, t_data *data, int h)
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
		else if (*content == '0')
			data->map[h][w] = 0;
		else if (*content == '1')
			data->map[h][w] = 1;
		else if (isinset(*content, "NSEW"))
		{
			ret = get_posdir(data, *content, w, h);
			if (ret)
				return (ret);
		}
		else
			return (ERR_CHAR);
		if (*content)
			content++;
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

static int	is_col_topdown_closed(t_data *data, int col)
{
	int	row;
	int	wall_encountered;

	row = 0;
	wall_encountered = 0;
	while (row < data->map_h)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		row++;
	}
	return (1);
}

static int	is_col_bottomup_closed(t_data *data, int col)
{
	int	row;
	int	wall_encountered;

	row = data->map_h - 1;
	wall_encountered = 0;
	while (row >= 0)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		row--;
	}
	return (1);
}

static int	is_row_left_right_closed(t_data *data, int row)
{
	int	col;
	int	wall_encountered;

	col = 0;
	wall_encountered = 0;
	while (col < data->map_w)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		col++;
	}
	return (1);
}

static int	is_row_right_left_closed(t_data *data, int row)
{
	int	col;
	int	wall_encountered;

	col = data->map_w - 1;
	wall_encountered = 0;
	while (col >= 0)
	{
		if (data->map[row][col] == 1)
			wall_encountered = 1;
		else if (data->map[row][col] == 0)
		{
			if (!wall_encountered)
				return (0);
		}
		else if (data->map[row][col] == 9)
			wall_encountered = 0;
		col--;
	}
	return (1);
}

int	is_map_closed(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < data->map_h)
	{
		if (!is_row_left_right_closed(data, row) || !is_row_right_left_closed(data, row))
			return (ERR_MAP_NOT_CLOSED);
		row++;
	}
	while (col < data->map_w)
	{
		if (!is_col_topdown_closed(data, col) || !is_col_bottomup_closed(data, col))
			return (ERR_MAP_NOT_CLOSED);
		col++;
	}
	return (SUCCESS);
}

int	parse_map(t_line *scene, t_data *data)
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
