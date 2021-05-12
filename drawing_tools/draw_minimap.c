/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:54:56 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 14:32:57 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_colour(int	floor_col, char gridchar)
{
	if (gridchar == '1')
		return (create_trgb(0, 20, 200, 200));
	else if (gridchar == '0')
		return (floor_col);
	else if (gridchar == '2')
		return (create_trgb(0, 140, 20, 200));
	else if (gridchar == ' ')
		return (create_trgb(0, 20, 150, 150));
	else
		return (floor_col);
}

void	fill_minimap(t_data *d)
{
	t_rect	rect;
	int		i;
	int		j;
	char	gridchar;

	i = -1;
	while (++i < d->mt.max_y)
	{
		j = -1;
		while (++j < d->mt.max_x)
		{
			gridchar = d->mt.grid[i][j];
			rect.x = j * d->mt.minimap_size;
			rect.y = i * d->mt.minimap_size;
			rect.width = d->mt.minimap_size;
			rect.height = d->mt.minimap_size;
			rect.border_width = 0;
			rect.fill_col = get_colour(d->mp.floor_col, gridchar);
			fill_rect(&rect, d->m.img.addr, d->m.win_w);
		}
	}
}
