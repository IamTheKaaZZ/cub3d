/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_rect_triangle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:58:19 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 15:58:49 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool	ft_is_in_rect_triangle(t_point px, t_point p1, t_point p2, t_point p3)
{
	float	area_in;
	float	calc1;
	float	calc2;
	float	calc3;

	area_in = area_triangle_pyth(p1, p2, p3);
	calc1 = area_triangle_pyth(px, p2, p3);
	calc2 = area_triangle_pyth(p1, px, p3);
	calc3 = area_triangle_pyth(p1, p2, px);
	return ((area_in == (calc1 + calc2 + calc3)));
}
