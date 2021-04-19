/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_circle_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:53:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 16:07:23 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Fill a circle with a given radius and colour
**		FUN SHAPES
**	fill_circle(&img2, 400, colour);
**	fill_rect_triangle(&img, 200, 500, colour);
**	t_point	p[3];
**	p[0].x = 100;
**	p[0].y = 50;
**	p[1].x = 300;
**	p[1].y = 800;
**	p[2].x = 1000;
**	p[2].y = 400;
**	fill_triangle(&img, p, colour);
*/

void	fill_circle(t_image *img, int radius, int colour)
{
	int	dsq;
	int x;
	int	y;

	img->line_length /= 4;
	x = 0;
	while (x <= radius * 2)
	{
		y = 0;
		while (y <= radius * 2)
		{
			dsq = pow((x - radius), 2) + pow((y - radius), 2);
			if (!(dsq > (int)pow(radius, 2)))
				img->address[(x * img->line_length) + y] = colour;
			y++;
		}
		x++;
	}
}
