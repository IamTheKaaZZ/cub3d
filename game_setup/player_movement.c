/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:47:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 17:12:34 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	player_move_up(t_data *d)
{
	int	moved_y;

	// -1 for the offset
	if (d->mp.minimap_size != 0)
		moved_y = (int)(d->pl.map_pos.y - 1.5 - 1) / d->mp.minimap_size;
	else
		moved_y = (int)(d->pl.map_pos.y - 1.5 - 1) / DEFAULT_TILE_SIZE;
	if (!ft_ischrinset(" 1", d->mp.grid[moved_y][(int)d->pl.grid_pos.x]))
	{
		d->pl.map_pos.y -= 1.5;
		if (moved_y < (int)d->pl.grid_pos.y)
			d->pl.grid_pos.y--;
	}
}

static void	player_move_down(t_data *d)
{
	int moved_y;

	// -7 for the offset
	if (d->mp.minimap_size != 0)
		moved_y = (int)(d->pl.map_pos.y + 1.5 + 4) / d->mp.minimap_size;
	else
		moved_y = (int)(d->pl.map_pos.y + 1.5 + 4) / DEFAULT_TILE_SIZE;
	if (!ft_ischrinset(" 1", d->mp.grid[moved_y][(int)d->pl.grid_pos.x]))
	{
	d->pl.map_pos.y += 1.5;
	if (moved_y > (int)d->pl.grid_pos.y)
		d->pl.grid_pos.y++;
	}
}

static void	player_move_left(t_data *d)
{
	int	moved_x;

	// -1 for the offset
	if (d->mp.minimap_size != 0)
		moved_x = (int)(d->pl.map_pos.x - 1.5 - 1) / d->mp.minimap_size;
	else
		moved_x = (int)(d->pl.map_pos.x - 1.5 - 1) / DEFAULT_TILE_SIZE;
	if (!ft_ischrinset(" 1", d->mp.grid[(int)d->pl.grid_pos.y][moved_x]))
	{
		d->pl.map_pos.x -= 1.5;
		if (moved_x < (int)d->pl.grid_pos.x)
			d->pl.grid_pos.x--;
	}
}

static void	player_move_right(t_data *d)
{
	int	moved_x;

	// -7 for the offset
	if (d->mp.minimap_size != 0)
		moved_x = (int)(d->pl.map_pos.x + 1.5 + 4) / d->mp.minimap_size;
	else
		moved_x = (int)(d->pl.map_pos.x + 1.5 + 4) / DEFAULT_TILE_SIZE;
	if (!ft_ischrinset(" 1", d->mp.grid[(int)d->pl.grid_pos.y][moved_x]))
	{
		d->pl.map_pos.x += 1.5;
		if (moved_x > (int)d->pl.grid_pos.x)
			d->pl.grid_pos.x++;
	}
}

void	movement(t_data *d)
{
	if (d->key.w)
		player_move_up(d);
	if (d->key.s)
		player_move_down(d);
	if (d->key.a)
		player_move_left(d);
	if (d->key.d)
		player_move_right(d);
	if (d->key.l_arr)
	{
		d->pl.angle -= 0.1;
		if (d->pl.angle < 0)
			d->pl.angle += 2 * M_PI;
		d->pl.delta.x = 5 * cos(d->pl.angle);
		d->pl.delta.y = 5 * sin(d->pl.angle);
	}
	if (d->key.r_arr)
	{
		d->pl.angle += 0.1;
		if (d->pl.angle > 2 * M_PI)
			d->pl.angle -= 2 * M_PI;
		d->pl.delta.x = 5 * cos(d->pl.angle);
		d->pl.delta.y = 5 * sin(d->pl.angle);
	}
	refresh_screen(d);
}
