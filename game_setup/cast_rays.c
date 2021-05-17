/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:22:21 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 15:51:22 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_rays(t_data *d)
{
	double	ray_angle;
	int		i;

	ray_angle = d->pl.angle - (d->rays.fov / 2);
	i = -1;
	while (++i < d->m.win_w)
	{
		d->rays.array[i].angle = ray_angle;
		get_shortest_ray_len(&d->rays.array[i], &d->mp, &d->pl);
		ray_angle += d->rays.fov / d->m.win_w;
	}
}
