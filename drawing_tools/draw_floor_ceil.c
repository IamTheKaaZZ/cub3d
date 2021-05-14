/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:06:11 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 17:32:48 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceiling(t_data *d)
{
	t_rect	ceil;

	ceil.x = 0;
	ceil.y = 0;
	ceil.width = d->m.win_w;
	ceil.height = d->m.win_h / 2;
	ceil.fill_col = d->sc.ceil_col;
	fill_rect(&ceil, d->m.img.addr, d->m.win_w);
}

void	draw_floor(t_data *d)
{
	t_rect	floor;

	floor.x = 0;
	floor.y = d->m.win_h / 2;
	floor.width = d->m.win_w;
	floor.height = d->m.win_h / 2;
	floor.fill_col = d->sc.floor_col;
	fill_rect(&floor, d->m.img.addr, d->m.win_w);
}
