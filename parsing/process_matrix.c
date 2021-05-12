/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:49:24 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 14:42:29 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int valid_data(t_data *d)
{
	d->mp.n_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->mp.n_text.path,
		&d->mp.n_text.data.img_w, &d->mp.n_text.data.img_h);
	d->mp.s_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->mp.s_text.path,
		&d->mp.s_text.data.img_w, &d->mp.s_text.data.img_h);
	d->mp.w_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->mp.w_text.path,
		&d->mp.w_text.data.img_w, &d->mp.w_text.data.img_h);
	d->mp.e_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->mp.e_text.path,
		&d->mp.e_text.data.img_w, &d->mp.e_text.data.img_h);
	d->mp.sprite.data.img = mlx_xpm_file_to_image(d->m.mlx, d->mp.sprite.path,
		&d->mp.sprite.data.img_w, &d->mp.sprite.data.img_h);
	printf("%c and angle = %f\n", d->pl.dir, d->pl.angle);
	if (d->pl.dir == 0 || !d->mp.n_text.data.img || !d->mp.s_text.data.img
		|| !d->mp.e_text.data.img || !d->mp.sprite.data.img)
		return (0);
	flush_data(d, NO_ERROR, FALSE);
	return (1);
}

static int	valid_and_player(t_data *d, size_t x, size_t y)
{
	if (d->mt.grid[y][x] == ' ')
	{
		printf("Got into space check, x = %zu, y = %zu\n", x, y);
		if (!ft_ischrinset(" 1", d->mt.grid[y][x - 1])
			|| !ft_ischrinset(" 1", d->mt.grid[y][x + 1])
			|| !ft_ischrinset(" 1", d->mt.grid[y - 1][x])
			|| !ft_ischrinset(" 1", d->mt.grid[y + 1][x]))
			return (0);
	}
	else if (!ft_ischrinset("012NESW", d->mt.grid[y][x]))
		return (0);
	if (ft_ischrinset("NSEW", d->mt.grid[y][x]))
	{
		if (d->pl.dir != 0)
			return (0);
		setup_player_data(d, x, y);
	}
	return (1);
}

static int	check_map(t_data *d)
{
	d->mt.y = 0;
	while (d->mt.y < d->mt.max_y)
	{
		d->mt.x = 0;
		while (d->mt.x < d->mt.max_x)
		{
			if (d->mt.y == 0 || d->mt.y == d->mt.max_y - 1
				|| d->mt.x == 0 || d->mt.x == d->mt.max_x - 1)
			{
				printf("Got into edge check, x = %d y = %d\n",d->mt.x , d->mt.y);
				if (!ft_ischrinset(" 1", d->mt.grid[d->mt.y][d->mt.x]))
					return (0);
			}
			else
				if (!valid_and_player(d, d->mt.x, d->mt.y))
					return (0);
			d->mt.x++;
		}
		d->mt.y++;
	}
	return (1);
}

static int	create_matrix_line(t_data *d, size_t i, void *content)
{
	int	curr_len;

	d->mt.grid[i] = (char *)ft_calloc(d->mt.max_x + 1, sizeof(char));
	if (!d->mt.grid[i])
	{
		free_matrix(&d->mt.grid);
		return (0);
	}
	curr_len = ft_strlen((char *)content);
	if (curr_len < d->mt.max_x)
	{
		ft_memcpy(d->mt.grid[i], content, curr_len);
		ft_memset(d->mt.grid[i] + curr_len, ' ', d->mt.max_x - curr_len);
	}
	else
		ft_memcpy(d->mt.grid[i], content, d->mt.max_x);
	return (1);
}

int	create_matrix(t_data *d)
{
	t_list	*current;
	int		i;

	d->mt.grid = (char **)ft_calloc((d->mt.max_y + 1), sizeof(char *));
	if (!d->mt.grid)
		return (0);
	current = d->lst->next;
	i = 0;
	while (i < d->mt.max_y)
	{
		if (!create_matrix_line(d, i++, current->content))
			return (0);
		current = current->next;
	}
	ft_lstmemdel_clear(&d->lst, ft_memdel);
	if (!check_map(d) || !valid_data(d))
		return (0);
	return (1);
}
