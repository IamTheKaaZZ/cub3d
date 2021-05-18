/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:24:12 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/18 16:33:38 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double	get_height(t_data *d, double dist)
{
	double	scaled_dist;

	scaled_dist = dist * SCALE;
	return ((SCALE / scaled_dist) * d->rays.dist_proj_plane);
}

static int	get_start_x_sprite(t_data *d, t_sprite *sprite, double width)
{
	int		x;
	int		scr_centre;
	double	spr_centre;

	scr_centre = d->m.win_w / 2;
	spr_centre = tan(sprite->rotation) * d->rays.dist_proj_plane;
	x = scr_centre + spr_centre - width / 2;
	return (x);
}

static int	get_start_y_sprite(t_data *d, double height)
{
	int		y;
	int		scr_centre;
	double	spr_centre;

	scr_centre = d->m.win_h / 2;
	spr_centre = height / 2;
	y = scr_centre - spr_centre;
	if (y < 0)
		y = 0;
	return (y);
}

static void	draw_one_sprite(t_data *d, t_sprite *sprite)
{
	t_rect	rect;
	double	column_width;
	int		i;
	int		j;
	int		pos_x;

	rect.height = get_height(d, sprite->dist);
	rect.y = get_start_y_sprite(d, rect.height);
	rect.x = get_start_x_sprite(d, sprite, rect.height);
	rect.tex = sprite->text;
	column_width = rect.height / sprite->text.img_h;
	i = -1;
	while (++i < sprite->text.img_w)
	{
		j = -1;
		while (++j < column_width)
		{
			pos_x = (int)(rect.x + (i - 1) * column_width + j);
			if (pos_x >= 0 && pos_x <= d->m.win_w - 1
				&& sprite->dist < d->rays.array[pos_x].len)
			{
				draw_sprite_strip(d, &rect, i, pos_x);
			}
		}
	}
}

void	draw_sprites(t_data *d)
{
	int			i;
	t_sprite	*sprite;

	i = -1;
	while (++i < d->sc.sprite_count)
	{
		sprite = &d->sc.sprites[i];
		if (sprite->is_visible)
			draw_one_sprite(d, sprite);
	}
}
