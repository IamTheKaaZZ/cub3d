/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rect_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:51:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/10 17:47:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Fill a square with a given height, width and colour
*/

void	fill_rect(t_image *img, int width, int height, int colour)
{
	int	h;
	int	w;

	img->line_len /= 4;
	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			img->addr[(h * img->line_len) + w] = colour;
			w++;
		}
		h++;
	}
}

void	fill_map_rect(t_data *d, t_bg *bg, int width, int height)
{
	size_t	h;
	size_t	w;

	bg->map2d.line_len /= 4;
	h = d->mt.y_off;
	while (h < height * d->mt.y)
	{
		w = d->mt.x_off;
		while (w < width * d->mt.y)
		{
			//if (d->mt.matrix[d->mt.y][d->mt.x] == 1)
				bg->map2d.addr[((h) * bg->map2d.line_len) + (w)] = bg->col1;
			w++;
		}
		h++;
	}
}
