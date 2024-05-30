/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:53 by nrea              #+#    #+#             */
/*   Updated: 2024/05/30 15:12:41 by qgiraux          ###   ########.fr       */
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

# define SCREEN_W 1024
# define SCREEN_H 768
# define ALPHA 0.06
# define SPEED 0.02
# define STRAFE 0.01

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

	int			map_w;
	int			map_h;
	int			map[24][24];
	int			keypress[6];
}	t_data;

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

/* srcs/colors.c */
int			ft_lerp(int c1, int c2, double f);
int			rgb_to_int(unsigned char r, unsigned char g, unsigned char b);

/*srcs/events.c*/
int			ft_keypress(int key, t_data *data);
int			ft_keyrelease(int key, t_data *data);
int			ft_keyact(t_data *data);
/*srcs/exit.c*/
void		ft_exit_mlx_init(t_data *data);
void		ft_exit_mlx_window(t_data *data);
/* srcs/math_utils.c */
int			ft_sign(int value);
int			ft_abs_int(int value);
t_vector2d	ft_apply2dmat(t_vector2d point, double m[2][2]);
void		ft_scalar_mul(t_vector2d *p, double scalar);

/*srcs/parsing_utils.c*/
int			ft_check_extension(char *s);
/*srcs/pixel.c*/
void		ft_pixel(t_img *screen_img, int x, int y, int color);
/* srcs/utils.c*/
void		ft_free_split(char **split);
int			ft_split_size(char **splitted);
t_vector2d	ft_compute_abs_diff(t_vector2d p0, t_vector2d p1);
/*srcs/win_utils.c*/
void		ft_print_cmd(void);
int			ft_destroy_window(t_data *data);
void		ft_end_safe(t_data *data);

void		ft_cast_angles(t_data data);
void		ft_calculate(t_rayCast caster, t_data data);
int			ft_set_walls(t_data *data);
void		draw_dispatch(t_rayCast caster, t_data data, t_draw_p p);
#endif
