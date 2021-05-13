/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:49:50 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 17:12:19 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_fourmultiple(t_data *d)
{
	int	tilesize;
	int	max_x;
	int	screen_w;

	max_x = d->mp.max_x;
	screen_w = d->m.win_w;
	while ((screen_w / 4) % max_x != 0)
		max_x--;
	tilesize = (screen_w / 4) / max_x;
	return (tilesize);
}

/*
**	player radius is the player offset for the minimap
*/

void	setup_player_data(t_data *d, int x, int y)
{
	d->pl.dir = d->mp.grid[y][x];
	d->mp.minimap_size = get_fourmultiple(d);
	d->pl.grid_pos.x = x;
	d->pl.map_pos.x = x * d->mp.minimap_size + (d->mp.minimap_size / 2) - 2;
	if (d->pl.map_pos.x < 0)
		d->pl.map_pos.x = x * DEFAULT_TILE_SIZE + (DEFAULT_TILE_SIZE / 2) - 2;
	d->pl.grid_pos.y = y;
	d->pl.map_pos.y = y * d->mp.minimap_size + (d->mp.minimap_size / 2) - 2;
	if (d->pl.map_pos.y < 0)
		d->pl.map_pos.y = y * DEFAULT_TILE_SIZE + (DEFAULT_TILE_SIZE / 2) - 2;
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

	player.x = d->pl.map_pos.x + d->mp.minimap_size;
	player.y = d->pl.map_pos.y + d->mp.minimap_size;
	player.radius = 2;
	player.border_width = 0;
	player.fill_col = create_trgb(0, 255, 10, 10);
	fill_circle(&player, d->m.img.addr, d->m.win_w);
	line.start_x = player.x + player.radius;
	line.start_y = player.y + player.radius;
	line.end_x = player.x + player.radius + d->pl.delta.x * 5;
	line.end_y = player.y + player.radius + d->pl.delta.y * 5;
	line.colour = create_trgb(0, 255, 10, 10);
	draw_line(&line, d->m.img.addr, d->m.win_w);
}