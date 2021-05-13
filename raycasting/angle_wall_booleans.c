/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_wall_booleans.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:19:40 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 17:20:14 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool	is_facing_south(double angle)
{
	if (angle >= 0 && angle <= M_PI)
		return (1);
	return (0);
}

t_bool	is_facing_west(double angle)
{
	if (angle >= M_PI_2 && angle <= M_PI_2 * 3)
		return (1);
	return (0);
}

char	get_wall_dir(t_ray *ray, t_map *map, int x, int y)
{
	if (x == 0)
		return ('E');
	if (x == map->max_x)
		return ('W');
	if (y == 0)
		return ('S');
	if (y == map->max_y)
		return ('N');
	if (ray->side == 'H')
	{
		if (map->grid[y - 1][x] != 1 && is_facing_south(ray->angle))
			return ('S');
		if (map->grid[y + 1][x] != 1 && !is_facing_south(ray->angle))
			return ('N');
	}
	if (ray->side == 'V')
	{
		if (map->grid[y][x - 1] != 1 && is_facing_west(ray->angle))
			return ('W');
		if (map->grid[y][x + 1] != 1 && !is_facing_west(ray->angle))
			return ('E');
	}
	return (0);
}

t_bool	is_wall(t_ray *ray, t_map *map, double x, double y)
{
	ray->pos.x = x;
	ray->pos.y = y;
	if ((int)x < 0 || (int)x > map->max_x || (int)y < 0 || (int)y > map->max_y)
	{
		ray->len = INT_MAX;
		return (1);
	}
	if ((int)y == map->max_y)
	{
		ray->obst = '1';
		ray->dir = 'N';
		return (1);
	}
	ray->obst = map->grid[(int)y][(int)x];
	if (ray->obst == '1')
	{
		ray->dir = get_wall_dir(ray, map, (int)x, (int)y);
		return (1);
	}
	return (0);
}
