/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:47:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 16:28:39 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	player_move_up(t_data *d)
{
	int	moved_y;

	// -1 for the offset
	moved_y = (int)(d->pl.scr_pos.y - 2.5 - 1) / d->mt.cub_size;
	if (!ft_ischrinset(" 1", d->mt.matrix[moved_y][(int)d->pl.map_pos.x]))
	{
		d->pl.scr_pos.y -= 2.5;
		if (moved_y < (int)d->pl.map_pos.y)
			d->pl.map_pos.y--;
	}
}

static void	player_move_down(t_data *d)
{
	int moved_y;

	// -7 for the offset
	moved_y = (int)(d->pl.scr_pos.y + 2.5 + 7) / d->mt.cub_size;
	if (!ft_ischrinset(" 1", d->mt.matrix[moved_y][(int)d->pl.map_pos.x]))
	{
	d->pl.scr_pos.y += 2.5;
	if (moved_y > (int)d->pl.map_pos.y)
		d->pl.map_pos.y++;
	}
}

static void	player_move_left(t_data *d)
{
	int	moved_x;

	// -1 for the offset
	moved_x = (int)(d->pl.scr_pos.x - 2.5 - 1) / d->mt.cub_size;
	if (!ft_ischrinset(" 1", d->mt.matrix[(int)d->pl.map_pos.y][moved_x]))
	{
		d->pl.scr_pos.x -= 2.5;
		if (moved_x < (int)d->pl.map_pos.x)
			d->pl.map_pos.x--;
	}
}

static void	player_move_right(t_data *d)
{
	int	moved_x;

	// -7 for the offset
	moved_x = (int)(d->pl.scr_pos.x + 2.5 + 7) / d->mt.cub_size;
	if (!ft_ischrinset(" 1", d->mt.matrix[(int)d->pl.map_pos.y][moved_x]))
	{
		d->pl.scr_pos.x += 2.5;
		if (moved_x > (int)d->pl.map_pos.x)
			d->pl.map_pos.x++;
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
			d->pl.angle += 2 * PI;
		d->pl.delta.x = 5 * cos(d->pl.angle);
		d->pl.delta.y = 5 * sin(d->pl.angle);
	}
	printf("Player angle is %f with dx = %f and dy = %f\n", d->pl.angle, d->pl.delta.x, d->pl.delta.y);
	if (d->key.r_arr)
	{
		d->pl.angle += 0.1;
		if (d->pl.angle > 2 * PI)
			d->pl.angle -= 2 * PI;
		d->pl.delta.x = 5 * cos(d->pl.angle);
		d->pl.delta.y = 5 * sin(d->pl.angle);
	}
	printf("Player angle is %f with dx = %f and dy = %f\n", d->pl.angle, d->pl.delta.x, d->pl.delta.y);
	destroy_image(d, d->pl.img.ptr, d->pl.img.addr);
	destroy_image(d, d->bg.map2d.ptr, d->bg.map2d.addr);
	destroy_image(d, d->bg.map3d.ptr, d->bg.map3d.addr);
	init_bg(d);
	init_player(d);
}
