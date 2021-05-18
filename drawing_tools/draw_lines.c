/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:39:10 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/18 17:47:12 by bcosters         ###   ########.fr       */
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

void	draw_rays(t_data *d, t_player *play)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < d->m.win_w)
	{
		line.start_x = play->grid.x * d->mp.tile_size + d->mp.tile_size;
		line.start_y = play->grid.y * d->mp.tile_size + d->mp.tile_size;
		line.end_x = line.start_x + cos(d->rays.array[i].angle) * d->rays.array[i].len * d->mp.tile_size;
		line.end_y = line.start_y + sin(d->rays.array[i].angle) * d->rays.array[i].len * d->mp.tile_size;
		line.colour = create_trgb(0, 220, 50, 50);
		draw_line(&line, d->m.img.addr, d->m.win_w);
	}
}
