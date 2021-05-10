/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:01:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/10 17:48:11 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_2d_map(t_data *d)
{
	int	cub_x;
	int	cub_y;

	cub_x = (d->m.win_w / 2) / d->mt.maxlen;
	cub_y = d->m.win_h / d->mt.height;
	//printf("cubx = %d, cuby = %d\n", cub_x, cub_y);
	d->bg.map2d.line_len /= 4;
	d->mt.y = 0;
	while (d->mt.y < d->mt.height)
	{
		d->mt.x = 0;
		while (d->mt.x < d->mt.maxlen)
		{
			d->mt.x_off = d->mt.x * cub_x;
			d->mt.y_off = d->mt.y * cub_y;
			if (d->mt.matrix[d->mt.y][d->mt.x] == 1)
				fill_map_rect(d, &d->bg, cub_x, cub_y);
			d->mt.x++;
		}
		d->mt.y++;
	}
}
