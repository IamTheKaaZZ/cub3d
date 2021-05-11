/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:48:47 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 17:27:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ray(t_data *d, float length, int colour)
{
	int	line_len;
	t_point	end;
	int		slope;
	int		y;
	int		x;

	line_len = d->pl.ray.line_len / 4;
	end.x = d->pl.scr_pos.x + cos(d->pl.angle) * length;
	end.y = d->pl.scr_pos.y + sin(d->pl.angle) * length;
	slope = (int)((d->pl.scr_pos.y - end.y) / (d->pl.scr_pos.x - end.x));
	y = 0;
	while (y < length)
	{
		x = 0;
		while (x < length)
		{
			if (slope == y / x)
				d->pl.ray.addr[(y * line_len) + x] = colour;
			x++;
		}
		y++;
	}
}
