/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_triangle_bh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:57:06 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 15:57:36 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	area_triangle_bh(t_point p1, t_point p2, t_point p3)
{
	float	calc;
	float	calc1;
	float	calc2;
	float	calc3;

	calc1 = p1.x * (p2.y - p3.y);
	calc2 = p2.x * (p3.y - p1.y);
	calc3 = p3.x * (p1.y - p2.y);
	calc = (calc1 + calc2 + calc3) / 2;
	return (fabs(calc));
}
