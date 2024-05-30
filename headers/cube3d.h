/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:53 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 15:59:54 by nrea             ###   ########.fr       */
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

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define DEFAULT_CEILING 0x0000FF
# define DEFAULT_FLOOR 0xCCCCCC
# define DEFAULT_NORTH_PATH "default_north_path"// A remplace par image par defaut
# define DEFAULT_SOUTH_PATH "default_south_path"// A remplace par image par defaut
# define DEFAULT_EAST_PATH "default_east_path"// A remplace par image par defaut
# define DEFAULT_WEST_PATH "default_west_path"// A remplace par image par defaut
#define	SUCCESS	0
#define	ERR_INVALID_EXTENSION	1
#define	ERR_OPEN	2
#define	ERR_INTERNAL	3
#define	ERR_COLOR	4
#define	ERR_TEX	5
#define	ERR_CHAR	6
#define	ERR_EMPTY	7
#define	ERR_POS_ALREADY_SET	8
#define	ERR_POS_NOT_SET	9
#define	ERR_MAP_NOT_CLOSED	10
#define	ERR_MAP_DIMENSIONS	11
#define	ERR_NO_MAP	12
#define	ERR_USAGE	13

#define	ERROR_LIST	"SUCCESS !;\
Extensions must be .cub;\
Scene:;\
An internal error has occured;\
Invalid color;\
parsing texture path issue;\
Invalid character found at line start;\
Invalid map character or empty line in map definition;\
The position can only be set once;\
The starting position and direction must be set;\
The map is not closed;\
The map must be at least 3x3;\
Dude... You forgot to put a map;\
Usage: ./cub3D [path_to_scene]"




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

	int			map_w;
	int			map_h;
	int			**map;
}	t_data;

/* srcs/colors.c */
int			ft_lerp(int c1, int c2, double f);
int			rgb_to_int(unsigned char r, unsigned char g, unsigned char b);

/*srcs/events.c*/
int			ft_keypress(int key, t_data *data);
/*srcs/exit.c*/
void		ft_exit_mlx_init(t_data *data);
void		ft_exit_mlx_window(t_data *data);
/* srcs/math_utils.c */
int			ft_sign(int value);
int			ft_abs_int(int value);
t_vector2d	ft_apply2dmat(t_vector2d point, double m[2][2]);
void		ft_scalar_mul(t_vector2d *p, double scalar);


/*srcs/pixel.c*/
void		ft_pixel(t_img *screen_img, int x, int y, int color);
/* srcs/utils.c*/
void		ft_free_split(char **split);
int			ft_split_size(char **splitted);
int			free_map(int **map, int map_h);


/*srcs/win_utils.c*/
void		ft_print_cmd(void);
int			ft_destroy_window(t_data *data);
void		ft_end_safe(t_data *data);
#endif

typedef struct	s_line
{
	char			*content;
	struct s_line	*next;
}	t_line;

/*srcs/parsing_utils.c*/
int	ft_check_extension(char *s);
int	isinset(char c, char *set);
int	is_all_digits(char *s);
int	check_if_all_digits(char *s1, char *s2, char *s3);


/*srcs/scene_parser/map_closing.c*/
int	is_map_closed(t_data *data);

/*srcs/scene_parser/populate_map.c*/
int	populate_map(t_line *scene, t_data *data);

/*srcs/scene_parser/set_text_and_col.c*/
int	get_color_info(int	*color, char *s);
int	get_texture_path(char *content, char **path);


/*srcs/scene_parser/map_dimensions.c*/
int	find_map_dimensions(t_line *scene, int *w, int *h);


int		load_scene(char *file_path, t_line **scene);
void	free_scene(t_line **scene);
int		error_handler(int error_code);
int		parse_scene(t_line **scene, t_data *data);
int		free_map(int **map, int map_h);
