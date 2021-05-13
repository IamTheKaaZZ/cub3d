/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:01:30 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 13:00:07 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Fill any triangle with 3 given points and colour
*/

void	fill_triangle(t_triangle *tri, int *imgaddr, int screen_width)
{
	t_point	px;
	int		maxx;
	int		maxy;

	maxx = ft_max(tri->p1.x, tri->p2.x, tri->p3.x);
	maxy = ft_max(tri->p1.y, tri->p2.y, tri->p3.y);
	px.y = ft_min(tri->p1.y, tri->p2.y, tri->p3.y);
	while (px.y <= maxy)
	{
		px.x = ft_min(tri->p1.x, tri->p2.x, tri->p3.x);;
		while (px.x <= maxx)
		{
			if (ft_is_in_triangle(px, tri->p1, tri->p2, tri->p3))
				imgaddr[((int)px.y * screen_width) + (int)px.x] = tri->fill_col;
			px.x++;
		}
		px.y++;
	}
}
