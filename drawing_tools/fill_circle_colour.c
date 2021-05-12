/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_circle_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:53:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 16:37:37 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	degree_to_radian(double degrees)
{
	return (degrees * M_PI / 180.0);
}

double	radian_to_degree(double radian)
{
	return (radian * 180.0 / M_PI);
}

void	fill_circle(t_circle *circle, int *imgaddr, int screen_width)
{
	int	dsq;
	int x;
	int	y;

	x = 0;
	while (x <= circle->radius * 2)
	{
		y = 0;
		while (y <= circle->radius * 2)
		{
			dsq = (int)pow((x - circle->radius), 2) + (int)pow((y - circle->radius), 2);
			if (!(dsq > (int)pow(circle->radius, 2)))
				imgaddr[((x + circle->y) * screen_width) + y + circle->x] = circle->fill_col;
			y++;
		}
		x++;
	}
}
