/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_calcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:49:50 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 16:22:12 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_player_data(t_data *d, int x, int y)
{
	d->pl.dir = d->mt.matrix[y][x];
	d->mt.cub_size = (d->m.win_w / 2) / d->mt.maxlen;
	d->pl.map_pos.x = x;
	d->pl.scr_pos.x = x * d->mt.cub_size + (d->mt.cub_size / 2) - 4;
	d->pl.map_pos.y = y;
	d->pl.scr_pos.y = y * d->mt.cub_size + (d->mt.cub_size / 2) - 4;
	if (d->pl.dir == 'E')
		d->pl.angle = 0;
	if (d->pl.dir == 'N')
		d->pl.angle = PI / 2;
	if (d->pl.dir == 'W')
		d->pl.angle = PI;
	if (d->pl.dir == 'S')
		d->pl.angle = 3 * PI / 2;
	d->pl.delta.x = 5 * cos(d->pl.angle);
	d->pl.delta.y = 5 * sin(d->pl.angle);
}
