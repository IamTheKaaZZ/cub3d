/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_strip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:02:02 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 11:07:04 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_sprite_strip(t_data *d, t_rect *spr, int x_tex, int x_img)
{
	double	step;
	double	tex_pos;
	int		y;
	int		y_tex;
	int		colour;

	step = 1.0 * spr->tex.img_h / spr->height;
	tex_pos = (spr->y - (d->m.win_h / 2) + (spr->height / 2)) * step;
	y = -1;
	while (++y < spr->height && y < d->m.win_h)
	{
		y_tex = (int)tex_pos & (spr->tex.img_h - 1);
		tex_pos += step;
		colour = spr->tex.img.addr[y_tex * spr->tex.img_h + x_tex];
		if (colour < 0)
			continue ;
		if (d->key.u_arr)
			colour |= 250 << 24;
		d->m.img.addr[(spr->y * d->m.win_w)
			+ (y * d->m.win_w) + x_img] = colour;
	}
}
