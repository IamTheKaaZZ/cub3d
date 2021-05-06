/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:49:24 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/06 16:35:48 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	valid_and_player(t_data *d, size_t x, size_t y)
{
	if (d->mt.matrix[y][x] == ' ')
	{
		printf("Got into space check, x = %zu, y = %zu\n", x, y);
		if (!ft_ischrinset(" 1", d->mt.matrix[y][x - 1])
			|| !ft_ischrinset(" 1", d->mt.matrix[y][x + 1])
			|| !ft_ischrinset(" 1", d->mt.matrix[y - 1][x])
			|| !ft_ischrinset(" 1", d->mt.matrix[y + 1][x]))
			return (0);
	}
	else if (!ft_ischrinset("012NESW", d->mt.matrix[y][x]))
		return (0);
	if (ft_ischrinset("NSEW", d->mt.matrix[y][x]))
	{
		if (d->pl.dir != 0)
			return (0);
		d->pl.dir = d->mt.matrix[y][x];
		d->pl.pos.x = x;
		d->pl.pos.y = y;
	}
	return (1);
}

static int	check_map(t_data *d)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < d->mt.height)
	{
		x = 0;
		while (x < d->mt.maxlen)
		{
			if (y == 0 || y == d->mt.height - 1
				|| x == 0 || x == d->mt.maxlen - 1)
			{
				printf("Got into edge check, x = %zu y = %zu\n",x , y);
				if (!ft_ischrinset(" 1", d->mt.matrix[y][x]))
					return (0);
			}
			else
				if (!valid_and_player(d, x, y))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	create_matrix_line(t_data *d, size_t i, void *content)
{
	size_t	curr_len;

	d->mt.matrix[i] = (char *)ft_calloc(d->mt.maxlen + 1, sizeof(char));
	if (!d->mt.matrix[i])
	{
		free_matrix(&d->mt.matrix);
		return (0);
	}
	curr_len = ft_strlen((char *)content);
	if (curr_len < d->mt.maxlen)
	{
		ft_memcpy(d->mt.matrix[i], content, curr_len);
		ft_memset(d->mt.matrix[i] + curr_len, ' ', d->mt.maxlen - curr_len);
	}
	else
		ft_memcpy(d->mt.matrix[i], content, d->mt.maxlen);
	return (1);
}

int	create_matrix(t_data *d)
{
	t_list	*current;
	size_t		i;

	d->mt.matrix = (char **)ft_calloc((d->mt.height + 1), sizeof(char *));
	if (!d->mt.matrix)
		return (0);
	current = d->lst->next;
	i = 0;
	while (i < d->mt.height)
	{
		if (!create_matrix_line(d, i++, current->content))
			return (0);
		current = current->next;
	}
	ft_lstmemdel_clear(&d->lst, ft_memdel);
	if (!check_map(d))
		return (0);
	return (1);
}
