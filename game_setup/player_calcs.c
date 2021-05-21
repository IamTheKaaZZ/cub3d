/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:49:50 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 11:23:58 by bcosters         ###   ########.fr       */
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
	d->pl.grid.x = x + 0.5;
	d->pl.grid.y = y + 0.5;
	if (d->mp.player_dir == 'E')
		d->pl.angle = degree_to_radian(360);
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

	draw_rays(d, &d->pl);
	player.x = d->pl.grid.x * d->mp.tile_size + d->mp.tile_size;
	player.y = d->pl.grid.y * d->mp.tile_size + d->mp.tile_size;
	player.radius = ceil(d->mp.tile_size / 4);
	player.fill_col = create_trgb(0, 255, 10, 10);
	fill_circle(&player, d->m.img.addr, d->m.win_w);
}
