/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:31:33 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 14:58:53 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	update_angle(t_data *d, t_sprite *sprite)
{
	double	dx;
	double	dy;
	double	angle;

	dx = sprite->pos.x - d->pl.map_pos.x;
	dy = sprite->pos.y - d->pl.map_pos.y;
	angle = atan2(dx, dy) - d->pl.angle;
	sprite->rotation = radian_within_circle(angle);
}

static void	update_visibility(t_data *d, t_sprite *sprite)
{
	double	delta_angle;

	delta_angle = sprite->rotation + d->pl.angle;
	delta_angle = d->pl.angle - delta_angle;
	if (delta_angle < -M_PI)
		delta_angle += 2 * M_PI;
	if (delta_angle > M_PI)
		delta_angle -= 2 * M_PI;
	delta_angle = fabs(delta_angle);
	if (delta_angle < d->rays.fov / 2 + degree_to_radian(4))
		sprite->is_visible = 1;
	else
		sprite->is_visible = 0;
}

static void	update_distance(t_data *d, t_sprite *sprite)
{
	double	dx;
	double	dy;

	dx = sprite->pos.x - d->pl.map_pos.x;
	dy = sprite->pos.y - d->pl.map_pos.y;
	sprite->dist = sqrt(pow(dx, 2) + pow(dy, 2));
}

static void	update_order(t_data *d, t_sprite *sprites)
{
	t_sprite	temp;
	int			i;
	int			j;

	i = -1;
	while (++i < d->sc.sprite_count)
	{
		j = -1;
		while (++j < d->sc.sprite_count - 1)
		{
			if (sprites[j].dist < sprites[j + 1].dist)
			{
				temp = sprites[j];
				sprites[j] = sprites[j + 1];
				sprites[j + 1] = temp;
			}
		}
	}
}

void	refresh_sprites(t_data *d)
{
	t_sprite	*current;
	int			i;

	i = -1;
	while (++i < d->sc.sprite_count)
	{
		current = &d->sc.sprites[i];
		update_angle(d, current);
		update_visibility(d, current);
		update_distance(d, current);
	}
	update_order(d, d->sc.sprites);
}
