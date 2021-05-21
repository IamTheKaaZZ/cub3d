/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_and_deg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:21:48 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 11:48:49 by bcosters         ###   ########.fr       */
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

double	radian_within_circle(double radian)
{
	double	circle;

	circle = 2 * M_PI;
	radian = fmod(radian, circle);
	if (radian < 0)
		radian += 2 * M_PI;
	return (radian);
}
