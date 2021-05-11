/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rect_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:51:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 10:37:34 by bcosters         ###   ########.fr       */
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
	int	line_len;

	line_len = img->line_len / 4;
	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			img->addr[(h * line_len) + w] = colour;
			w++;
		}
		h++;
	}
}

void	fill_2dmap(t_data *d, int cub_size, int colour)
{
	size_t	height;
	size_t	width;
	size_t	h;
	size_t	w;
	int		line_len;

	line_len = d->bg.map2d.line_len / 4;
	height = cub_size * (d->mt.y + 1);
	width = cub_size * (d->mt.x + 1);
	h = d->mt.y_off + 1;
	while (h < height)
	{
		w = d->mt.x_off + 1;
		while (w < width)
		{
			d->bg.map2d.addr[(h * line_len) + w] = colour;
			w++;
		}
		h++;
	}
}
