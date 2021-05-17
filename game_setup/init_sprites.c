/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:53:52 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 11:53:08 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_sprites(t_map *map, t_scene *sc)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (++y < map->max_y)
	{
		x = -1;
		while (++x < map->max_x)
		{
			if (map->grid[y][x] == '2')
			{
				sc->sprites[i].pos.x = x + 0.5;
				sc->sprites[i].pos.y = y + 0.5;
				sc->sprites[i].text = sc->sprite;
				i++;
			}
		}
	}
}

void	init_sprites(t_data *d)
{
	d->sc.sprites = (t_sprite *)malloc(d->sc.sprite_count * sizeof(t_sprite));
	if (!d->sc.sprites)
		flush_data(d, DATA_ERR, TRUE);
	get_sprites(&d->mp, &d->sc);
}
