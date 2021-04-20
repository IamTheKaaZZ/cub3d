/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:00:25 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/20 15:01:33 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Fill a rectangular triangle with a given height, width and colour
*/

void	fill_rect_triangle(t_image *img, int width, int height, int colour)
{
	t_point	px;
	t_point	p1;
	t_point	p2;
	t_point	p3;

	p1.x = width;
	p1.y = 0;
	p2.x = 0;
	p2.y = height;
	p3.x = p1.x;
	p3.y = p2.y;
	img->line_len /= 4;
	px.y = 0;
	while (px.y <= height)
	{
		px.x = 0;
		while (px.x <= width)
		{
			if (ft_is_in_rect_triangle(px, p1, p2, p3))
				img->addr[(px.y * img->line_len) + px.x] = colour;
			px.x++;
		}
		px.y++;
	}
}
