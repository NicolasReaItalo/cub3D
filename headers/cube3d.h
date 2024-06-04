/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:53 by nrea              #+#    #+#             */
/*   Updated: 2024/06/04 11:58:04 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include  "../minilibx-linux/mlx.h"

# define SUCCESS	0
# define ERR_INVALID_EXTENSION	1
# define ERR_OPEN	2
# define ERR_INTERNAL	3
# define ERR_COLOR	4
# define ERR_TEX	5
# define ERR_CHAR	6
# define ERR_EMPTY	7
# define ERR_POS_ALREADY_SET	8
# define ERR_POS_NOT_SET	9
# define ERR_MAP_NOT_CLOSED	10
# define ERR_MAP_DIMENSIONS	11
# define ERR_NO_MAP	12
# define ERR_USAGE	13
# define ERR_NOTEX	14
# define ERR_TEX_ALREADY_SET	15
# define ERR_COL_ALREADY_SET	16
# define ERR_NOT_ALL_SET	17
# define SCREEN_W 1332
# define SCREEN_H 999
# define ALPHA 0.065
# define SPEED 0.1
# define STRAFE 0.08
# define SCALE 0.3
# define ERROR_LIST	"SUCCESS !;\
Extensions must be .cub;\
Scene:;\
An internal error has occured;\
Invalid color;\
parsing texture path issue;\
Invalid character;\
Invalid map character or empty line in map definition;\
The position can only be set once;\
The starting position and direction must be set;\
The map is not closed;\
The map must be at least 3x3;\
Dude... You forgot to put a map;\
Usage: ./cub3D [path_to_scene];\
No texture found;\
A texture path can only be set up once per scene;\
Color already set;\
All Color and texture informations must be set;"

typedef struct s_draw_p
{
	int		start;
	int		end;
	int		y;
	int		texn;
	int		texs;
	int		texe;
	int		texw;
	double	nstep;
	double	sstep;
	double	estep;
	double	wstep;
}	t_draw_p;
typedef struct s_vector2d
{
	double	x;
	double	y;
}	t_vector2d;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	*data;
}	t_img;

typedef struct s_tex
{
	t_img	img;
	int		width;
	int		height;
	char	*path;
}	t_tex;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		screen_img;

	t_tex		n_img;
	t_tex		w_img;
	t_tex		s_img;
	t_tex		e_img;

	int			f_color;
	int			c_color;

	t_vector2d	pos;
	t_vector2d	dir;
	t_vector2d	cam;

	int			mousex;

	double		mmap_size;
	t_img		map_img;
	int			map_w;
	int			map_h;
	int			**map;
	int			keypress[6];
}	t_data;

typedef struct s_line
{
	char			*content;
	struct s_line	*next;
}	t_line;

typedef struct s_rayCast
{
	int			case_x;
	int			case_y;
	t_vector2d	ray;
	t_vector2d	delta;
	t_vector2d	sidedist;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			x;
	double		x_shift;
}	t_rayCast;

/*srcs/events.c*/
int			ft_keypress(int key, t_data *data);
int			ft_keyrelease(int key, t_data *data);

/*srcs/exit.c*/
void		ft_exit_mlx_init(t_data *data);
void		ft_exit_mlx_window(t_data *data);
/* srcs/math_utils.c */
t_vector2d	ft_apply2dmat(t_vector2d point, double m[2][2]);

/*srcs/pixel.c*/
void		ft_pixel(t_img *screen_img, int x, int y, int color);
/* srcs/utils.c*/
void		ft_free_split(char **split);
int			ft_split_size(char **splitted);
int			free_map(int **map, int map_h);

/*srcs/win_utils.c*/
int			ft_destroy_window(t_data *data);
void		ft_end_safe(t_data *data);
void		free_walls(t_data *data);

/*srcs/data_operations.c*/
void		free_tex_path(t_data *data);
int			init_data(t_data *data);
int			parser_init(int argc, char **argv, t_data *data);
void		init_cam(t_data *data);

/*srcs/parsing_utils.c*/
int			ft_check_extension(char *s);
int			isinset(char c, char *set);
int			check_valid_colors(char *s1, char *s2, char *s3);
char		*strip(char *s);

/*srcs/scene_parser/map_closing.c*/
int			is_map_closed(t_data *data);

/*srcs/scene_parser/populate_map.c*/
int			populate_map(t_line *scene, t_data *data);

/*srcs/scene_parser/set_text_and_col.c*/
int			get_color_info(int	*color, char *s);
int			get_texture_path(char *content, char **path);

/*srcs/scene_parser/map_dimensions.c*/
int			find_map_dimensions(t_line *scene, int *w, int *h);

/*srcs/scene_parser/scene_loader.c*/
void		free_scene(t_line **scene);
int			load_scene(char *file_path, t_line **scene);

/*srcs/scene_parser/parse_error_handler.c*/
int			error_handler(int error_code);

/*srcs/scene_parser/parse_scene.c*/
int			parse_scene(t_line **scene, t_data *data);

/*srcs/scene_parser/rayCast_angles.c*/
void		ft_cast_angles(t_data data);

/*srcs/scene_parser/rayCast_calculate.c*/
void		ft_calculate(t_rayCast caster, t_data data);

/*srcs/scene_parser/rayCast_draw.c*/
void		draw_dispatch(t_rayCast caster, t_data data, t_draw_p p);

/*srcs/scene_parser/set_imgs.c*/
int			ft_set_walls(t_data *data);

/*srcs/scene_parser/movements.c*/
int			ft_keyact(t_data *data);

/*srcs/scene_parser/minimap.c*/
int			ft_minimap(t_data *data);

#endif
