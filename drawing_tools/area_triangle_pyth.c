/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_triangle_pyth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:55:57 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 15:56:24 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	area_triangle_pyth(t_point p1, t_point p2, t_point p3)
{
	int	calc1;
	int	calc2;
	int	calc3;

	calc1 = p1.x * (p2.y - p3.y);
	calc2 = p2.x * (p3.y - p1.y);
	calc3 = p3.x * (p1.y - p2.y);
	return (abs(calc1 + calc2 + calc3));
}
