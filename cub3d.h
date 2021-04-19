/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:43:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 17:16:19 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3_H
# define CUB3_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
# else
#  ifdef _WIN32
#   include <windows.h>
#  endif
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
# endif
# include "minilibx_mms/mlx.h"
# include "minilibx_opengl/mlx.h"

/*
**	DEFINES
*/

# define MAXRES_X 5120
# define MAXRES_Y 2880
enum	e_error_msg
{
	NO_CUB_FILE_TYPE,
	INVALID_FILE,
	NOT_ENOUGH_ARGS,
	TOO_MANY_ARGS,
	INVALID_FLAG
};

/*
**	STRUCTS
*/

typedef struct s_image
{
	void	*ptr;
	int		*address;
	int		bitsperpixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	double	win_height;
	double	win_width;
}			t_mlx;

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
int	ft_max(int a, int b, int c);
int	ft_min(int a, int b, int c);
int	create_inverse_trgb(int colour);
int	create_trgb(int t, int r, int g, int b);
void	ft_error_handling(int errnum);

#endif