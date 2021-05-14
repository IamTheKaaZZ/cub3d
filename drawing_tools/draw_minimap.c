/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:54:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 17:30:12 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_colour(int	floor_col, char gridchar)
{
	if (ft_ischrinset("1 ", gridchar))
		return (create_trgb(0, 20, 200, 200));
	else if (gridchar == '0')
		return (floor_col);
	else if (gridchar == '2')
		return (create_trgb(0, 140, 20, 200));
	else
		return (floor_col);
}

static void	minimap(t_data *d, t_rect *rect, int i, int j)
{
	char	gridchar;

	gridchar = d->mp.grid[i][j];
	rect->x = j * d->mp.tile_size + d->mp.tile_size;
	rect->y = i * d->mp.tile_size + d->mp.tile_size;
	rect->width = d->mp.tile_size;
	rect->height = d->mp.tile_size;
	rect->fill_col = get_colour(d->sc.floor_col, gridchar);
	fill_rect(rect, d->m.img.addr, d->m.win_w);
}

void	fill_minimap(t_data *d)
{
	t_rect		rect;
	t_triangle	tri;
	int			i;
	int			j;

	tri.fill_col = create_trgb(0, 200, 20, 75);
	i = -1;
	while (++i < d->mp.max_y)
	{
		j = -1;
		while (++j < d->mp.max_x)
		{
			minimap(d, &rect, i, j);
		}
	}
	rect.x = d->mp.tile_size;
	rect.y = d->mp.tile_size;
	rect.width = 0.5 * d->mp.tile_size;
	rect.height = d->mp.max_y * d->mp.tile_size;
	rect.fill_col = create_trgb(0, 200, 20, 75);
	fill_rect(&rect, d->m.img.addr, d->m.win_w);
	rect.x = d->mp.tile_size * d->mp.max_x + d->mp.tile_size / 2;
	rect.y = d->mp.tile_size;
	fill_rect(&rect, d->m.img.addr, d->m.win_w);
	rect.x = d->mp.tile_size;
	rect.y = d->mp.tile_size;
	rect.width = d->mp.max_x * d->mp.tile_size;
	rect.height = 0.5 * d->mp.tile_size;
	fill_rect(&rect, d->m.img.addr, d->m.win_w);
	rect.x = d->mp.tile_size;
	rect.y = d->mp.tile_size * d->mp.max_y + d->mp.tile_size / 2;
	fill_rect(&rect, d->m.img.addr, d->m.win_w);
}
