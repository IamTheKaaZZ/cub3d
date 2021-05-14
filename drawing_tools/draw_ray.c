/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:48:47 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 17:49:20 by bcosters         ###   ########.fr       */
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

void	draw_rays(t_data *d)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < d->m.win_w)
	{
		line.start_x = d->pl.map_pos.x + d->mp.tile_size + 2;
		line.start_y = d->pl.map_pos.y + d->mp.tile_size + 2;
		line.end_x = d->pl.map_pos.x + d->mp.tile_size + 2
			+ cos(d->rays.array[i].angle)
			* d->mp.tile_size * d->rays.array[i].len;
		line.end_y = d->pl.map_pos.y + d->mp.tile_size + 2
			+ sin(d->rays.array[i].angle)
			* d->mp.tile_size * d->rays.array[i].len;
		line.colour = create_trgb(0, 255, 10, 10);
		draw_line(&line, d->m.img.addr, d->m.win_w);
	}
}