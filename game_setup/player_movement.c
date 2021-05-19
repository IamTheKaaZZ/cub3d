/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:47:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/19 15:00:30 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	player_move_up(t_data *d)
{
	double	moved_y;
	double	moved_x;
	double	angle;
	double	coll_y;
	double	coll_x;

	angle = d->pl.angle;
	moved_y = d->pl.grid.y + MOVE_SPEED * sin(angle);
	moved_x = d->pl.grid.x + MOVE_SPEED * cos(angle);
	coll_y = moved_y + COLL * sin(angle);
	coll_x = moved_x + COLL * cos(angle);
	if (!ft_ischrinset(" 12", d->mp.grid[(int)(coll_y)][(int)(coll_x)]))
	{
		d->pl.grid.y += MOVE_SPEED * sin(angle);
		d->pl.grid.x += MOVE_SPEED * cos(angle);
	}
}

static void	player_move_down(t_data *d)
{
	double	moved_y;
	double	moved_x;
	double	angle;
	double	coll_y;
	double	coll_x;

	angle = d->pl.angle;
	moved_y = d->pl.grid.y - MOVE_SPEED * sin(angle);
	moved_x = d->pl.grid.x - MOVE_SPEED * cos(angle);
	coll_y = moved_y - COLL * sin(angle);
	coll_x = moved_x + COLL * cos(angle);
	if (!ft_ischrinset(" 12", d->mp.grid[(int)(coll_y)][(int)(coll_x)]))
	{
		d->pl.grid.y -= MOVE_SPEED * sin(angle);
		d->pl.grid.x -= MOVE_SPEED * cos(angle);
	}
}

static void	player_move_left(t_data *d)
{
	double	moved_y;
	double	moved_x;
	double	angle;
	double	coll_y;
	double	coll_x;

	angle = d->pl.angle + degree_to_radian(90);
	moved_y = d->pl.grid.y - MOVE_SPEED * sin(angle);
	moved_x = d->pl.grid.x - MOVE_SPEED * cos(angle);
	coll_y = moved_y - COLL * sin(angle);
	coll_x = moved_x + COLL * cos(angle);
	if (!ft_ischrinset(" 12", d->mp.grid[(int)(coll_y)][(int)(coll_x)]))
	{
		d->pl.grid.y -= MOVE_SPEED * sin(angle);
		d->pl.grid.x -= MOVE_SPEED * cos(angle);
	}
}

static void	player_move_right(t_data *d)
{
	double	moved_y;
	double	moved_x;
	double	angle;
	double	coll_y;
	double	coll_x;

	angle = d->pl.angle + degree_to_radian(90);
	moved_y = d->pl.grid.y + MOVE_SPEED * sin(angle);
	moved_x = d->pl.grid.x + MOVE_SPEED * cos(angle);
	coll_y = moved_y + COLL * sin(angle);
	coll_x = moved_x - COLL * cos(angle);
	if (!ft_ischrinset(" 12", d->mp.grid[(int)(coll_y)][(int)(coll_x)]))
	{
		d->pl.grid.y += MOVE_SPEED * sin(angle);
		d->pl.grid.x += MOVE_SPEED * cos(angle);
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
		d->pl.angle -= degree_to_radian(4);
		if (d->pl.angle < 0)
			d->pl.angle += 2 * M_PI;
	}
	if (d->key.r_arr)
	{
		d->pl.angle += degree_to_radian(4);
		if (d->pl.angle > 2 * M_PI)
			d->pl.angle -= 2 * M_PI;
	}
}
