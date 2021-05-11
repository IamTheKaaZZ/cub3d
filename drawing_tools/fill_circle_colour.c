/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_circle_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:53:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 11:20:04 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_circle(t_image *img, int radius, int colour)
{
	int	dsq;
	int x;
	int	y;
	int	line_len;

	line_len = img->line_len / 4;
	x = 0;
	while (x <= radius * 2)
	{
		y = 0;
		while (y <= radius * 2)
		{
			dsq = (int)pow((x - radius), 2) + (int)pow((y - radius), 2);
			if (!(dsq > (int)pow(radius, 2)))
				img->addr[(x * line_len) + y] = colour;
			else
				img->addr[(x * line_len) + y] = colour + (255 << 24);
			y++;
		}
		x++;
	}
}
