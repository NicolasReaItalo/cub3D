/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:56:53 by nrea              #+#    #+#             */
/*   Updated: 2024/05/28 13:53:53 by nrea             ###   ########.fr       */
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

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 800

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

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	screen_img;



	int		**map;



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
t_vector2d	ft_compute_abs_diff(t_vector2d p0, t_vector2d p1);
/*srcs/win_utils.c*/
void		ft_print_cmd(void);
int			ft_destroy_window(t_data *data);
void		ft_end_safe(t_data *data);
#endif


///PARSING

#define	SUCCESS	0
#define	ERR_INVALID_EXTENSION	1
#define	ERR_OPEN	2 // ajouter perror
#define	ERR_INTERNAL	3

typedef struct	s_line
{
	char			*content;
	struct s_line	*next;
}	t_line;

/*srcs/parsing_utils.c*/
int		ft_check_extension(char *s);
int		load_scene(char *file_path, t_line **scene);
void	free_scene(t_line **scene);
