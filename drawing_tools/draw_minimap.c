/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:54:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 11:06:31 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_colour(int	floor_col, int ceil_col, char gridchar)
{
	if (ft_ischrinset("1 ", gridchar))
		return (create_inverse_trgb(ceil_col));
	else if (gridchar == '0')
		return (floor_col);
	else if (gridchar == '2')
		return (create_inverse_trgb(floor_col));
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
	rect->fill_col = get_colour(d->sc.floor_col, d->sc.ceil_col, gridchar);
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
}
