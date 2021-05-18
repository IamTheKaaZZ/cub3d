/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_all_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:25:04 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/18 17:58:02 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	get_horiz_intersect_south(t_ray *ray, t_map *map, t_player *play)
{
	double	dist_y;
	double	dist_x;
	double	step_y;
	double	step_x;
	double	section_len;

	dist_y = ceil(play->grid.y);
	step_y = dist_y - play->grid.y;
	step_x = step_y / tan(ray->angle);
	dist_x = play->grid.x + step_x;
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, dist_x, dist_y))
		return ;
	step_y = 1;
	step_x = 1 / tan(ray->angle);
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	while (!is_wall(ray, map, dist_x, dist_y))
	{
		dist_y += step_y;
		dist_x += step_x;
		ray->len += section_len;
	}
}

void	get_horiz_intersect_north(t_ray *ray, t_map *map, t_player *play)
{
	double	dist_y;
	double	dist_x;
	double	step_y;
	double	step_x;
	double	section_len;

	dist_y = floor(play->grid.y);
	step_y = play->grid.y - dist_y;
	step_x = step_y / tan(ray->angle);
	dist_x = play->grid.x - step_x;
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, dist_x, dist_y - 1))
		return ;
	step_y = -1;
	step_x = -1 / tan(ray->angle);
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	while (!is_wall(ray, map, dist_x, dist_y - 1))
	{
		dist_y += step_y;
		dist_x += step_x;
		ray->len += section_len;
	}
}

void	get_vert_intersect_east(t_ray *ray, t_map *map, t_player *play)
{
	double	dist_y;
	double	dist_x;
	double	step_y;
	double	step_x;
	double	section_len;

	dist_x = ceil(play->grid.x);
	step_x = dist_x - play->grid.x;
	step_y = step_x * tan(ray->angle);
	dist_y = play->grid.y + step_y;
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, dist_x, dist_y))
		return ;
	step_x = 1;
	step_y = 1 * tan(ray->angle);
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	while (!is_wall(ray, map, dist_x, dist_y))
	{
		dist_x += step_x;
		dist_y += step_y;
		ray->len += section_len;
	}
}

void	get_vert_intersect_west(t_ray *ray, t_map *map, t_player *play)
{
	double	dist_y;
	double	dist_x;
	double	step_y;
	double	step_x;
	double	section_len;

	dist_x = floor(play->grid.x);
	step_x = play->grid.x - dist_x;
	step_y = step_x * tan(ray->angle);
	dist_y = play->grid.y - step_y;
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	ray->len += section_len;
	if (is_wall(ray, map, dist_x - 1, dist_y))
		return ;
	step_x = -1;
	step_y = -1 * tan(ray->angle);
	section_len = sqrt(pow(step_x, 2) + pow(step_y, 2));
	while (!is_wall(ray, map, dist_x - 1, dist_y))
	{
		dist_x += step_x;
		dist_y += step_y;
		ray->len += section_len;
	}
}
