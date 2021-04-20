/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rect_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:51:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/20 15:00:58 by bcosters         ###   ########.fr       */
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
