/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_circle_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:53:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 12:13:38 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_circle(t_circle *circle, int *imgaddr, int screen_width)
{
	double	angle;
	double	x;
	double	y;
	int		draw_x;
	int		draw_y;

	while (circle->radius--)
	{
		angle = 0;
		while (angle <= 360)
		{
			x = circle->radius * cos(degree_to_radian(angle));
			y = circle->radius * sin(degree_to_radian(angle));
			draw_x = circle->x + (int)x;
			draw_y = circle->y + (int)y;
			imgaddr[draw_y * screen_width + draw_x] = circle->fill_col;
			angle += 0.1;
		}
	}
}
