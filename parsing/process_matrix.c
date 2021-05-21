/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:49:24 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 12:57:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Final check + loading of the textures into images
*/

static int	valid_data(t_data *d)
{
	d->sc.n_text.img.ptr = mlx_xpm_file_to_image(d->m.mlx, d->sc.n_text.path,
			&d->sc.n_text.img_w, &d->sc.n_text.img_h);
	d->sc.s_text.img.ptr = mlx_xpm_file_to_image(d->m.mlx, d->sc.s_text.path,
			&d->sc.s_text.img_w, &d->sc.s_text.img_h);
	d->sc.w_text.img.ptr = mlx_xpm_file_to_image(d->m.mlx, d->sc.w_text.path,
			&d->sc.w_text.img_w, &d->sc.w_text.img_h);
	d->sc.e_text.img.ptr = mlx_xpm_file_to_image(d->m.mlx, d->sc.e_text.path,
			&d->sc.e_text.img_w, &d->sc.e_text.img_h);
	d->sc.sprite.img.ptr = mlx_xpm_file_to_image(d->m.mlx, d->sc.sprite.path,
			&d->sc.sprite.img_w, &d->sc.sprite.img_h);
	printf("%c and angle = %f\n", d->mp.player_dir, d->pl.angle);
	if (d->mp.player_dir == 0 || !d->sc.n_text.img.ptr
		|| !d->sc.s_text.img.ptr || !d->sc.e_text.img.ptr
		|| !d->sc.sprite.img.ptr || !d->sc.sprite_count)
		return (0);
	flush_data(d, NO_ERROR, FALSE);
	return (1);
}

static int	valid_and_player(t_map *map, t_data *d, int x, int y)
{
	if (!ft_ischrinset(" 1", map->grid[y][x]))
	{
		if (map->grid[y][x - 1] == ' ' || map->grid[y][x + 1] == ' '
			|| map->grid[y - 1][x] == ' ' || map->grid[y + 1][x] == ' ')
			return (0);
	}
	if (map->grid[y][x] == '2')
		d->sc.sprite_count++;
	if (ft_ischrinset("NSEW", map->grid[y][x]))
	{
		if (map->player_dir != 0)
			return (0);
		setup_player_data(d, x, y);
	}
	return (1);
}

static int	check_map(t_data *d, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			if (!ft_ischrinset(" 012NESW", map->grid[y][x]))
				return (0);
			if (y == 0 || y == map->max_y - 1
				|| x == 0 || x == map->max_x - 1)
			{
				if (!ft_ischrinset(" 1", map->grid[y][x]))
					return (0);
			}
			else
				if (!valid_and_player(map, d, x, y))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	create_matrix_line(t_map *map, size_t i, void *content)
{
	int	curr_len;

	map->grid[i] = (char *)ft_calloc(map->max_x + 1, sizeof(char));
	if (!map->grid[i])
	{
		free_matrix(&map->grid);
		return (0);
	}
	curr_len = ft_strlen((char *)content);
	if (curr_len < map->max_x)
	{
		ft_memcpy(map->grid[i], content, curr_len);
		ft_memset(map->grid[i] + curr_len, ' ', map->max_x - curr_len);
	}
	else
		ft_memcpy(map->grid[i], content, map->max_x);
	return (1);
}

int	create_matrix(t_data *d, t_list *game_map)
{
	t_list	*current;
	int		i;

	d->mp.grid = (char **)ft_calloc((d->mp.max_y + 1), sizeof(char *));
	if (!d->mp.grid)
		return (0);
	current = game_map->next;
	i = 0;
	while (i < d->mp.max_y)
	{
		if (!create_matrix_line(&d->mp, i++, current->content))
			return (0);
		current = current->next;
	}
	ft_lstmemdel_clear(&game_map, ft_memdel);
	if (!check_map(d, &d->mp) || !valid_data(d))
		return (0);
	return (1);
}
