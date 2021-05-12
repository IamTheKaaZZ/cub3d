/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:49:50 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 17:24:05 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	4 is the player offset for the minimap
*/

void	setup_player_data(t_data *d, int x, int y)
{
	d->pl.dir = d->mt.grid[y][x];
	d->mt.minimap_size = (d->m.win_w / 2) / d->mt.max_x;
	d->pl.grid_pos.x = x;
	d->pl.scr_pos.x = x * d->mt.minimap_size + (d->mt.minimap_size / 2) - 4;
	d->pl.grid_pos.y = y;
	d->pl.scr_pos.y = y * d->mt.minimap_size + (d->mt.minimap_size / 2) - 4;
	if (d->pl.dir == 'E')
		d->pl.angle = degree_to_radian(0);
	if (d->pl.dir == 'N')
		d->pl.angle = degree_to_radian(270);
	if (d->pl.dir == 'W')
		d->pl.angle = degree_to_radian(180);
	if (d->pl.dir == 'S')
		d->pl.angle = degree_to_radian(90);
	d->pl.delta.x = 5 * cos(d->pl.angle);
	d->pl.delta.y = 5 * sin(d->pl.angle);
}

void	refresh_player(t_data *d)
{
	t_circle	player;
	t_line		line;

	player.x = d->pl.scr_pos.x;
	player.y = d->pl.scr_pos.y;
	player.radius = 4;
	player.border_width = 0;
	player.fill_col = create_trgb(0, 255, 10, 10);
	fill_circle(&player, d->m.img.addr, d->m.win_w);
	line.start_x = d->pl.scr_pos.x + 4;
	line.start_y = d->pl.scr_pos.y + 4;
	line.end_x = d->pl.scr_pos.x + 4 + d->pl.delta.x * 10;
	line.end_y = d->pl.scr_pos.y + 4 + d->pl.delta.y * 10;
	line.colour = create_trgb(0, 255, 10, 10);
	draw_line(&line, d->m.img.addr, d->m.win_w);
}