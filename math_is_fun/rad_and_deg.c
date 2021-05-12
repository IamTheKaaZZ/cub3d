/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_and_deg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:21:48 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 17:22:13 by bcosters         ###   ########.fr       */
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
