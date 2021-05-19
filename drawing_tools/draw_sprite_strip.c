/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_strip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:02:02 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/19 16:34:00 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_sprite_strip(t_data *d, t_rect *spr, int x_tex, int x_img)
{
	double	step;
	double	tex_pos;
	int		y;
	int		y_tex;
	int		color;

	step = 1.0 * spr->tex.img_h / spr->height;
	tex_pos = (spr->y - (d->m.win_h / 2) + (spr->height / 2)) * step;
	y = -1;
	while (++y < spr->height && y < d->m.win_h)
	{
		y_tex = (int)tex_pos & (spr->tex.img_h - 1);
		tex_pos += step;
		color = spr->tex.img.addr[y_tex * spr->tex.img_h + x_tex];
		if (color < 0)
			continue ;
		/*color |= 250 << 24;*/
		d->m.img.addr[(spr->y * d->m.win_w)
			+ (y * d->m.win_w) + x_img] = color;
	}
}