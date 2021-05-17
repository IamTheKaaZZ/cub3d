/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:24:12 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 17:12:40 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double	get_height(t_data *d, double dist)
{
	double	scaled_dist;

	scaled_dist = dist * SCALE;
	return (SCALE / scaled_dist * d->rays.dist_proj_plane);
}

static int	get_x_sprite(t_data *d, t_sprite *sprite, double width)
{
	int		scr_centre;
	double	spr_centre;

	scr_centre = d->m.win_w / 2;
	spr_centre = tan(sprite->rotation) * d->rays.dist_proj_plane;
	return (scr_centre + spr_centre - width / 2);
}

static int	get_y_sprite(t_data *d, double height)
{
	int	y;

	y = d->m.win_h / 2 - height / 2;
	if (y < 0)
		y = 0;
	return (y);
}

static void	draw_one_sprite(t_data *d, t_sprite *sprite)
{
	t_rect	spr;
	double	col_width;
	int		i;
	int		j;
	int		img_x;

	spr.height = get_height(d, sprite->dist);
	spr.y = get_y_sprite(d, spr.height);
	spr.x = get_x_sprite(d, sprite, spr.height);
	spr.tex = sprite->text;
	col_width = spr.height / sprite->text.img_h;
	i = -1;
	while (++i < sprite->text.img_w)
	{
		j = -1;
		while (++j < col_width)
		{
			img_x = (int)(spr.x + (i - 1) * col_width + j);
			if (img_x >= 0 && img_x < d->m.win_w
				&& sprite->dist < d->rays.array[img_x].len)
				draw_sprite_strip(d, &spr, i, img_x);
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
