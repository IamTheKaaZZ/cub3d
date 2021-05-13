/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:59:25 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 13:04:22 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool	ft_is_in_triangle(t_point px, t_point p1, t_point p2, t_point p3)
{
	double	area_in;
	double	calc1;
	double	calc2;
	double	calc3;

	area_in = area_triangle_bh(p1, p2, p3);
	calc1 = area_triangle_bh(px, p2, p3);
	calc2 = area_triangle_bh(p1, px, p3);
	calc3 = area_triangle_bh(p1, p2, px);
	return (((int)area_in == (int)calc1 + (int)calc2 + (int)calc3));
}
