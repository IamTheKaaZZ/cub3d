/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:43:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/16 17:22:29 by bcosters         ###   ########.fr       */
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
**	STRUCTS
*/

typedef struct s_image
{
	void	*ptr;
	char	*address;
	int		bitsperpixel;
	int		line_length;
	int		endian;
}			t_image;

#endif