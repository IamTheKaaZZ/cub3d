/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:48:47 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 14:38:51 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_line *line, int *imgaddr, int screen_width)
{
	t_point px;
	int		pixels;
	t_point	delta;

	px.x = line->start_x;
	px.y = line->start_y;

	delta.x = line->end_x - line->start_x;
	delta.y = line->end_y - line->start_y;
	pixels = sqrt(pow(delta.x, 2) + pow(delta.y, 2));
	delta.x /= pixels;
	delta.y /= pixels;
	while (pixels)
	{
		imgaddr[((int)px.y * screen_width) + (int)px.x] = line->colour;
		px.x += delta.x;
		px.y += delta.y;
		pixels--;
	}
}
