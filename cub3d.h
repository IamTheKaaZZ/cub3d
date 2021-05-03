/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:43:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/03 17:09:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_opengl/mlx.h"

/*
**	DEFINES
*/

# define MAXRES_X 5120
# define MAXRES_Y 2880
# define ESCAPE_KEY 53
# define LEFT_ARR_KEY 123
# define RIGHT_ARR_KEY 124
# define UP_ARR_KEY 126
# define DOWN_ARR_KEY 125
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
enum	e_error_msg
{
	NO_CUB_FILE_TYPE,
	INVALID_FILE,
	NOT_ENOUGH_ARGS,
	TOO_MANY_ARGS,
	INVALID_FLAG,
	OPEN_ERR,
	READ_ERR,
	RES_ERR,
	RES_OVERFLOW
};

/*
**	STRUCTS
*/

typedef struct s_image
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		end;
}			t_image;

typedef struct s_col
{
	int	t;
	int	r;
	int	g;
	int	b;
}		t_col;

typedef struct s_bg
{
	t_image	bg1;
	t_image	bg2;
	int		colour;
}			t_bg;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	t_point	res;
	char	*n_text;
	char	*s_text;
	char	*w_text;
	char	*e_text;
	char	*sprite;
	t_col	floor;
	t_col	ceil;
}			t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	double	win_h;
	double	win_w;
}			t_mlx;

/*
**	MASTER STRUCT
*/

typedef struct s_data
{
	t_mlx	m;
	t_image	i;
	t_point	p;
	t_bg	bg;
	t_map	mp;
}			t_data;

/*
**	PROTOTYPES
*/

float	area_triangle_bh(t_point p1, t_point p2, t_point p3);
float	area_triangle_pyth(t_point p1, t_point p2, t_point p3);
void	fill_circle(t_image *img, int radius, int colour);
void	fill_rect(t_image *img, int width, int height, int colour);
void	fill_rect_triangle(t_image *img, int width, int height, int colour);
void	fill_triangle(t_image *img, t_point *points, int colour);
t_bool	ft_is_in_rect_triangle(t_point px, t_point p1, t_point p2, t_point p3);
t_bool	ft_is_in_triangle(t_point px, t_point p1, t_point p2, t_point p3);
int		ft_max(int a, int b, int c);
int		ft_min(int a, int b, int c);
int		create_inverse_trgb(int colour);
int		create_trgb(int t, int r, int g, int b);
void	ft_error_handling(int errnum);
void	parse_map(t_data *d, char *filename);

#endif