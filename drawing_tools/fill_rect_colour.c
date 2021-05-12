/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rect_colour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:51:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 12:55:53 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Fill a square with a given height, width and colour
*/

void	fill_rect(t_rect *rect, int *imgaddr, int screen_width)
{
	int	i;
	int	j;
	int	x;
	int	y;

	//rect->border_width--;
	i = -1;
	while (++i < rect->height)
	{
		j = -1;
		while (++j < rect->width)
		{
			x = rect->x + j;
			y = rect->y + i;
			imgaddr[(y * screen_width) + x] = rect->fill_col;
		}
	}
}
