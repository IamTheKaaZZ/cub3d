/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:01:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 16:02:05 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Fill any triangle with 3 given points and colour
*/

void	fill_triangle(t_image *img, t_point *points, int colour)
{
	t_point	px;
	int		maxx;
	int		maxy;

	maxx = ft_max(points[0].x, points[1].x, points[2].x);
	maxy = ft_max(points[0].y, points[1].y, points[2].y);
	img->line_length /= 4;
	px.y = 0;
	while (px.y <= maxy)
	{
		px.x = 0;
		while (px.x <= maxx)
		{
			if (ft_is_in_triangle(px, points[0], points[1], points[2]))
				img->address[(px.y * img->line_length) + px.x] = colour;
			px.x++;
		}
		px.y++;
	}
}
