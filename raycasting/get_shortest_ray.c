/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:28:26 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 11:47:01 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_horiz_intersect(t_ray *ray, t_map *map, t_player *play)
{
	ray->len = 0;
	if (ray->angle == degree_to_radian(180)
		|| ray->angle == degree_to_radian(360))
	{
		ray->len = INT_MAX;
		return ;
	}
	if (is_facing_south(ray->angle))
		get_horiz_intersect_south(ray, map, play);
	else
		get_horiz_intersect_north(ray, map, play);
}

static void	get_vert_intersect(t_ray *ray, t_map *map, t_player *play)
{
	ray->len = 0;
	if (ray->angle == degree_to_radian(90)
		|| ray->angle == degree_to_radian(270))
	{
		ray->len = INT_MAX;
		return ;
	}
	if (is_facing_west(ray->angle))
		get_vert_intersect_west(ray, map, play);
	else
		get_vert_intersect_east(ray, map, play);
}

void	get_shortest_ray_len(t_ray *ray, t_map *map, t_player *play)
{
	t_ray	horiz_intersect;
	t_ray	vert_intersect;

	horiz_intersect.angle = radian_within_circle(ray->angle);
	horiz_intersect.side = 'H';
	get_horiz_intersect(&horiz_intersect, map, play);
	vert_intersect.angle = radian_within_circle(ray->angle);
	vert_intersect.side = 'V';
	get_vert_intersect(&vert_intersect, map, play);
	if (horiz_intersect.len <= vert_intersect.len)
		*ray = horiz_intersect;
	else
		*ray = vert_intersect;
}
