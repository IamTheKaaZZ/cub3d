/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:16:02 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 15:12:32 by bcosters         ###   ########.fr       */
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

static void	fill_wall_strip(t_rect *wall, int *imgptr, t_mlx *m, t_ray *ray)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pox;

	step = 1.0 * wall->tex.img_h / wall->height;
	tex_pox = (wall->y - (m->win_h / 2) + (wall->height / 2)) * step;
	tex_x = get_bitmap_offset(ray, wall->tex.img_w);
	y = -1;
	while (++y < wall->height && y < m->win_h)
	{
		tex_y = (int)tex_pox & (wall->tex.img_h - 1);
		tex_pox += step;
		imgptr[(wall->y * m->win_w) + (y * m->win_w) + wall->x]
			= wall->tex.img.addr[tex_y * wall->tex.img_h + tex_x];
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

static double	get_wall_height_and_y(t_data *d, t_ray *ray, int *y)
{
	double	height;
	double	scaled_dist;
	double	fisheye_corr;
	double	scr_centre;
	double	wall_centre;

	fisheye_corr = cos(ray->angle - d->pl.angle);
	scaled_dist = ray->len * SCALE * fisheye_corr;
	height = (SCALE / scaled_dist) * d->rays.dist_proj_plane;
	scr_centre = d->m.win_h / 2;
	wall_centre = height / 2;
	*y = scr_centre - wall_centre;
	if (*y < 0)
		*y = 0;
	return (height);
}

void	draw_walls(t_data *d)
{
	t_rect	wall;
	t_ray	*ray;
	int		i;

	wall.y = 0;
	i = -1;
	while (++i < d->m.win_w)
	{
		ray = &d->rays.array[i];
		wall.height = get_wall_height_and_y(d, ray, &wall.y);
		wall.x = i;
		wall.tex = get_wall_text(&d->sc, ray->dir);
		fill_wall_strip(&wall, d->m.img.addr, &d->m, ray);
	}
}
