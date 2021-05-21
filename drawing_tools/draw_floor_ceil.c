/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:06:11 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 11:04:59 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_bitmap_offset(t_ray *ray, int bitmapwidth)
{
	double	remainder;
	int		offset;

	if (ray->side == 'H')
	{
		remainder = ray->pos.x - floor(ray->pos.x);
		offset = bitmapwidth * remainder;
	}
	if (ray->side == 'V')
	{
		remainder = ray->pos.y - floor(ray->pos.y);
		offset = bitmapwidth * remainder;
	}
	return (offset);
}

static void	fill_text_strip(t_rect *wall, int *imgptr, t_data *d, t_ray *ray)
{
	int			y;
	t_ipoint	tex;
	double		step;
	double		tex_pos;
	int			colour;

	step = 1.0 * wall->tex.img_h / wall->height;
	tex_pos = (wall->y) * step;
	tex.x = get_bitmap_offset(ray, d->m.win_w);
	y = -1;
	while (++y < wall->height && y < d->m.win_h)
	{
		tex.y = (int)tex_pos & (wall->tex.img_h - 1);
		tex_pos += step;
		colour = wall->tex.img.addr[tex.y * wall->tex.img_h + tex.x];
		if (d->key.u_arr)
			colour |= 200 << 24;
		imgptr[wall->y * d->m.win_w + y * d->m.win_w + wall->x] = colour;
	}
}

void	draw_ceiling(t_data *d)
{
	t_rect	ceil;
	t_ray	*ray;
	int		i;

	ceil.x = 0;
	ceil.y = 0;
	ceil.width = d->m.win_w;
	ceil.height = d->m.win_h / 2;
	if (!d->key.u_arr)
	{
		ceil.fill_col = d->sc.ceil_col;
		fill_rect(&ceil, d->m.img.addr, d->m.win_w);
	}
	else
	{
		i = -1;
		while (++i < d->m.win_w)
		{
			ray = &d->rays.array[i];
			ceil.tex = d->sc.n_text;
			fill_text_strip(&ceil, d->m.img.addr, d, &d->rays.array[i]);
		}
	}
}

void	draw_floor(t_data *d)
{
	t_rect	floor;
	t_ray	*ray;
	int		i;

	floor.x = 0;
	floor.y = d->m.win_h / 2;
	floor.width = d->m.win_w;
	floor.height = d->m.win_h / 2;
	if (!d->key.u_arr)
	{
		floor.fill_col = d->sc.floor_col;
		fill_rect(&floor, d->m.img.addr, d->m.win_w);
	}
	else
	{
		i = -1;
		while (++i < d->m.win_w)
		{
			ray = &d->rays.array[i];
			floor.tex = d->sc.s_text;
			fill_text_strip(&floor, d->m.img.addr, d, &d->rays.array[i]);
		}
	}
}
