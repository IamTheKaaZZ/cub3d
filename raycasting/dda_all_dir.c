/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_all_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:25:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 14:43:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	get_horiz_intersect_south(t_ray *ray, t_map *map, t_player *play)
{
	double	delta_y;
	double	delta_x;
	double	section_len;

	delta_y = ceil(play->grid.y);
	ray->step.y = delta_y - play->grid.y;
	ray->step.x = ray->step.y / tan(ray->angle);
	delta_x = play->grid.x + ray->step.x;
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, delta_x, delta_y))
		return ;
	ray->step.y = 1;
	ray->step.x = 1 / tan(ray->angle);
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	while (!is_wall(ray, map, delta_x, delta_y))
	{
		delta_y += ray->step.y;
		delta_x += ray->step.x;
		ray->len += section_len;
	}
}

void	get_horiz_intersect_north(t_ray *ray, t_map *map, t_player *play)
{
	double	delta_y;
	double	delta_x;
	double	section_len;

	delta_y = floor(play->grid.y);
	ray->step.y = play->grid.y - delta_y;
	ray->step.x = ray->step.y / tan(ray->angle);
	delta_x = play->grid.x - ray->step.x;
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, delta_x, delta_y - 1))
		return ;
	ray->step.y = -1;
	ray->step.x = 1 / tan(ray->angle);
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	while (!is_wall(ray, map, delta_x, delta_y - 1))
	{
		delta_y += ray->step.y;
		delta_x += ray->step.x;
		ray->len += section_len;
	}
}

void	get_vert_intersect_east(t_ray *ray, t_map *map, t_player *play)
{
	double	delta_y;
	double	delta_x;
	double	section_len;

	delta_x = ceil(play->grid.x);
	ray->step.x = delta_x - play->grid.x;
	ray->step.y = ray->step.x * tan(ray->angle);
	delta_y = play->grid.y + ray->step.y;
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, delta_x, delta_y))
		return ;
	ray->step.x = 1;
	ray->step.y = 1 * tan(ray->angle);
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	while (!is_wall(ray, map, delta_x, delta_y))
	{
		delta_x += ray->step.x;
		delta_y += ray->step.y;
		ray->len += section_len;
	}
}

void	get_vert_intersect_west(t_ray *ray, t_map *map, t_player *play)
{
	double	delta_y;
	double	delta_x;
	double	section_len;

	delta_x = floor(play->grid.x);
	ray->step.x = play->grid.x - delta_x;
	ray->step.y = ray->step.x * tan(ray->angle);
	delta_y = play->grid.y - ray->step.y;
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, delta_x - 1, delta_y))
		return ;
	ray->step.x = -1;
	ray->step.y = -1 * tan(ray->angle);
	section_len = sqrt(pow(ray->step.x, 2) + pow(ray->step.y, 2));
	while (!is_wall(ray, map, delta_x - 1, delta_y))
	{
		delta_x += ray->step.x;
		delta_y += ray->step.y;
		ray->len += section_len;
	}
}
