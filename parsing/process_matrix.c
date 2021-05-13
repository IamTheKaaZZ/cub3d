/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:49:24 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 17:38:35 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int valid_data(t_data *d)
{
	d->sc.n_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->sc.n_text.path,
		&d->sc.n_text.data.img_w, &d->sc.n_text.data.img_h);
	d->sc.s_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->sc.s_text.path,
		&d->sc.s_text.data.img_w, &d->sc.s_text.data.img_h);
	d->sc.w_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->sc.w_text.path,
		&d->sc.w_text.data.img_w, &d->sc.w_text.data.img_h);
	d->sc.e_text.data.img = mlx_xpm_file_to_image(d->m.mlx, d->sc.e_text.path,
		&d->sc.e_text.data.img_w, &d->sc.e_text.data.img_h);
	d->sc.sprite.data.img = mlx_xpm_file_to_image(d->m.mlx, d->sc.sprite.path,
		&d->sc.sprite.data.img_w, &d->sc.sprite.data.img_h);
	printf("%c and angle = %f\n", d->pl.dir, d->pl.angle);
	if (d->pl.dir == 0 || !d->sc.n_text.data.img || !d->sc.s_text.data.img
		|| !d->sc.e_text.data.img || !d->sc.sprite.data.img
			|| !d->sc.sprite_count)
		return (0);
	flush_data(d, NO_ERROR, FALSE);
	return (1);
}

static int	valid_and_player(t_data *d, size_t x, size_t y)
{
	if (d->mp.grid[y][x] == ' ')
	{
		printf("Got into space check, x = %zu, y = %zu\n", x, y);
		if (!ft_ischrinset(" 1", d->mp.grid[y][x - 1])
			|| !ft_ischrinset(" 1", d->mp.grid[y][x + 1])
			|| !ft_ischrinset(" 1", d->mp.grid[y - 1][x])
			|| !ft_ischrinset(" 1", d->mp.grid[y + 1][x]))
			return (0);
	}
	else if (!ft_ischrinset("012NESW", d->mp.grid[y][x]))
		return (0);
	if (d->mp.grid[y][x] == '2')
		d->sc.sprite_count++;
	if (ft_ischrinset("NSEW", d->mp.grid[y][x]))
	{
		if (d->pl.dir != 0)
			return (0);
		setup_player_data(d, x, y);
	}
	return (1);
}

static int	check_map(t_data *d)
{
	d->mp.y = 0;
	while (d->mp.y < d->mp.max_y)
	{
		d->mp.x = 0;
		while (d->mp.x < d->mp.max_x)
		{
			if (d->mp.y == 0 || d->mp.y == d->mp.max_y - 1
				|| d->mp.x == 0 || d->mp.x == d->mp.max_x - 1)
			{
				printf("Got into edge check, x = %d y = %d\n",d->mp.x , d->mp.y);
				if (!ft_ischrinset(" 1", d->mp.grid[d->mp.y][d->mp.x]))
					return (0);
			}
			else
				if (!valid_and_player(d, d->mp.x, d->mp.y))
					return (0);
			d->mp.x++;
		}
		d->mp.y++;
	}
	return (1);
}

static int	create_matrix_line(t_data *d, size_t i, void *content)
{
	int	curr_len;

	d->mp.grid[i] = (char *)ft_calloc(d->mp.max_x + 1, sizeof(char));
	if (!d->mp.grid[i])
	{
		free_matrix(&d->mp.grid);
		return (0);
	}
	curr_len = ft_strlen((char *)content);
	if (curr_len < d->mp.max_x)
	{
		ft_memcpy(d->mp.grid[i], content, curr_len);
		ft_memset(d->mp.grid[i] + curr_len, ' ', d->mp.max_x - curr_len);
	}
	else
		ft_memcpy(d->mp.grid[i], content, d->mp.max_x);
	return (1);
}

int	create_matrix(t_data *d)
{
	t_list	*current;
	int		i;

	d->mp.grid = (char **)ft_calloc((d->mp.max_y + 1), sizeof(char *));
	if (!d->mp.grid)
		return (0);
	current = d->lst->next;
	i = 0;
	while (i < d->mp.max_y)
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
