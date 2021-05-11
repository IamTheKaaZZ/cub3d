/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:01:53 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 12:13:22 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_2d_map(t_data *d)
{
	int	cub_size;

	cub_size = d->mt.cub_size;
	d->mt.y = 0;
	while (d->mt.y < d->mt.height)
	{
		d->mt.x = 0;
		while (d->mt.x < d->mt.maxlen)
		{
			d->mt.x_off = d->mt.x * cub_size;
			d->mt.y_off = d->mt.y * cub_size;
			if (d->mt.matrix[d->mt.y][d->mt.x] == '1')
				fill_2dmap(d, cub_size, create_trgb(0, 20, 200, 200));
			if (ft_ischrinset("02NSEW", d->mt.matrix[d->mt.y][d->mt.x]))
				fill_2dmap(d, cub_size, create_trgb(0, 150, 20, 215));
			if (d->mt.matrix[d->mt.y][d->mt.x] == ' ')
				fill_2dmap(d, cub_size, create_trgb(0, 20, 150, 150));
			d->mt.x++;
		}
		d->mt.y++;
	}
}
