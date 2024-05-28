/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:26:14 by nrea              #+#    #+#             */
/*   Updated: 2024/05/28 16:41:57 by nrea             ###   ########.fr       */
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


char	*strip_leading_zeroes(char *s)
{
	while(*s && *s=='0')
		s++;
	return (s);
}

int is_all_digits(char *s)
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
	splitted = ft_split(s, ',');
	if (!splitted)
		return (ERR_INTERNAL);
	if (ft_split_size(splitted) != 3)
		return(ft_free_split(splitted),ERR_COLOR);
	if (!is_all_digits(splitted[0])||!is_all_digits(splitted[1])||!is_all_digits(splitted[2]))
		return(ft_free_split(splitted),ERR_COLOR);
	r = ft_atoi(splitted[0]);
	g = ft_atoi(splitted[1]);
	b = ft_atoi(splitted[2]);
	if (r > 255 || g > 255 || b > 255)
		return(ft_free_split(splitted),ERR_COLOR);
	*color = r <<16| g <<8| b;
	ft_free_split(splitted);
	return(SUCCESS);
}



int	exit_safe()
{
	return 1;
}

int get_texture(t_img *tex, char *s, t_data *data)
{
	char	**splitted;

	splitted = ft_split(s, ' ');
	if(!splitted)
		return (ERR_INTERNAL);
	if(ft_split_size(splitted) != 2)
		return(ft_free_split(splitted),ERR_TEX);
	tex->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, splitted[1], &tex->width, &tex->height);
	if (!tex->mlx_img)
		return(ft_free_split(splitted), ERR_TEX);
	//mlx_get_data_addr a ajouter
	return (0);
}




int	parse_scene(t_line **scene, t_data *data)
{
	t_line	*s;
	int		ret;

	ret = 0;
	s = *scene;
	while (s)
	{
		if (ft_strlen(s->content))
		{
			if (!ft_strncmp(s->content, "NO", 2))
			{
				if (error_handler(get_texture(&data->N_img, s->content, data)) != 0)
					return(exit_safe()); // ajouter les paramaeters data et
			}
			else if (!ft_strncmp(s->content, "SO", 2))
			{
				if (error_handler(get_texture(&data->S_img, s->content, data)) != 0)
					return(exit_safe()); // ajouter les paramaeters data et
			}
			else if (!ft_strncmp(s->content, "WE", 2))
			{
				if (error_handler(get_texture(&data->W_img, s->content, data)) != 0)
					return(exit_safe()); // ajouter les paramaeters data et
			}
			else if (!ft_strncmp(s->content, "EA", 2))
			{
				if (error_handler(get_texture(&data->E_img, s->content, data)) != 0)
					return(exit_safe()); // ajouter les paramaeters data et
			}
			else if (!ft_strncmp(s->content, "F", 1))
			{
				if (error_handler(get_color_info(&data->f_color ,s->content)) != 0)
					return(exit_safe()); // ajouter les paramaeters data et
			}
			else if (!ft_strncmp(s->content, "C", 1))
			{
				if (error_handler(get_color_info(&data->c_color ,s->content)) != 0)
					return(exit_safe()); // ajouter les paramaeters
			}
			else if (ft_strchr(" 01NSWE",s->content[0]))
			{
				printf("parsing the map\n");
				return(0);
			}
			else
			{
				printf ("[DEBUG]invalid char \n");
				return (1); ////invalid character
			}
		}
		s = s->next;
	}
	return (0);
}
