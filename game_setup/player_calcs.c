/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:49:50 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 17:51:08 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_tile_size(t_map *map, int screen_width)
{
	int	tilesize;
	int	max_x;

	max_x = map->max_x;
	tilesize = (screen_width / 4) / max_x;
	if (tilesize > DEFAULT_TILE_SIZE)
		tilesize = DEFAULT_TILE_SIZE;
	return (tilesize);
}

/*
**	player radius is the player offset for the minimap
*/

void	setup_player_data(t_data *d, int x, int y)
{
	d->mp.player_dir = d->mp.grid[y][x];
	d->mp.tile_size = get_tile_size(&d->mp, d->m.win_w);
	d->pl.grid_pos.x = x;
	d->pl.map_pos.x = x * d->mp.tile_size + (d->mp.tile_size / 2) - 2;
	if (d->pl.map_pos.x < 0)
		d->pl.map_pos.x = x * DEFAULT_TILE_SIZE + (DEFAULT_TILE_SIZE / 2) - 2;
	d->pl.grid_pos.y = y;
	d->pl.map_pos.y = y * d->mp.tile_size + (d->mp.tile_size / 2) - 2;
	if (d->pl.map_pos.y < 0)
		d->pl.map_pos.y = y * DEFAULT_TILE_SIZE + (DEFAULT_TILE_SIZE / 2) - 2;
	if (d->mp.player_dir == 'E')
		d->pl.angle = degree_to_radian(0);
	if (d->mp.player_dir == 'N')
		d->pl.angle = degree_to_radian(270);
	if (d->mp.player_dir == 'W')
		d->pl.angle = degree_to_radian(180);
	if (d->mp.player_dir == 'S')
		d->pl.angle = degree_to_radian(90);
	d->pl.delta.x = 5 * cos(d->pl.angle);
	d->pl.delta.y = 5 * sin(d->pl.angle);
}

void	refresh_player(t_data *d)
{
	t_circle	player;
	//t_line		line;

	draw_rays(d);
	player.x = d->pl.map_pos.x + d->mp.tile_size;
	player.y = d->pl.map_pos.y + d->mp.tile_size;
	player.radius = 2;
	player.fill_col = create_trgb(0, 255, 10, 10);
	fill_circle(&player, d->m.img.addr, d->m.win_w);
	/*line.start_x = player.x + player.radius;
	line.start_y = player.y + player.radius;
	line.end_x = player.x + player.radius + d->pl.delta.x * 5;
	line.end_y = player.y + player.radius + d->pl.delta.y * 5;
	line.colour = create_trgb(0, 255, 10, 10);
	draw_line(&line, d->m.img.addr, d->m.win_w);*/
}