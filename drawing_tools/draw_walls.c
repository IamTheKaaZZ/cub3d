/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:16:02 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 13:06:58 by bcosters         ###   ########.fr       */
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

static void	fill_wall_strip(t_rect *wall, int *imgptr, t_data *d, t_ray *ray)
{
	int			y;
	t_ipoint	tex;
	double		step;
	double		tex_pos;
	int			colour;

	step = 1.0 * wall->tex.img_h / wall->height;
	tex_pos = (wall->y - wall->offset - (d->m.win_h / 2)
			+ (wall->height / 2)) * step;
	tex.x = get_bitmap_offset(ray, wall->tex.img_w);
	y = -1 + wall->offset;
	if (y < -1)
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

static t_text	get_wall_text(t_scene *sc, char dir)
{
	if (dir == 'N')
		return (sc->n_text);
	else if (dir == 'S')
		return (sc->s_text);
	else if (dir == 'E')
		return (sc->e_text);
	else
		return (sc->w_text);
}

static double	get_wall_height_and_y(t_data *d, t_ray *ray, t_rect *wall)
{
	double	height;
	double	scaled_dist;
	double	fisheye_corr;
	double	scr_centre;
	double	wall_centre;

	wall->offset = 0;
	fisheye_corr = cos(ray->angle - d->pl.angle);
	scaled_dist = ray->len * SCALE * fisheye_corr;
	height = (SCALE / scaled_dist) * d->rays.dist_proj_plane;
	scr_centre = d->m.win_h / 2;
	wall_centre = height / 2;
	wall->y = scr_centre - wall_centre;
	if (wall->y < 0)
		wall->y = 0;
	return (height);
}

/*
**	Ghetto jumping and crouching intensifies, NOT
*/

void	draw_walls(t_data *d)
{
	t_rect	wall;
	t_ray	*ray;
	int		i;

	d->wall = malloc(d->m.win_w * sizeof(t_rect));
	i = -1;
	while (++i < d->m.win_w)
	{
		ray = &d->rays.array[i];
		wall.height = get_wall_height_and_y(d, ray, &wall);
		wall.y += wall.offset;
		wall.x = i;
		wall.tex = get_wall_text(&d->sc, ray->dir);
		d->wall[i] = wall;
	}
	i = -1;
	while (++i < d->m.win_w)
		fill_wall_strip(&d->wall[i], d->m.img.addr, d, &d->rays.array[i]);
	free(d->wall);
}
