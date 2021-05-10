/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:16:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/10 16:31:41 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	error_check(t_data *d, int retval)
{
	if (retval < 0)
		flush_data(d, READ_ERR, 1);
	if (ft_ischrinset(" \t1", *d->mp.line) && d->m.win_w && d->m.win_h
		&& d->mp.n_text && d->mp.s_text && d->mp.w_text && d->mp.e_text
		&& d->mp.sprite && d->mp.floor_col && d->mp.ceil_col)
	{
		printf("Resolution is %d, %d\n", d->m.win_w, d->m.win_h);
		printf("North texture = %s\n", d->mp.n_text);
		printf("South texture = %s\n", d->mp.s_text);
		printf("West texture = %s\n", d->mp.w_text);
		printf("East texture = %s\n", d->mp.e_text);
		printf("Sprite texture = %s\n", d->mp.sprite);
		printf("Floor colour = %#X\n", d->mp.floor_col);
		printf("Ceiling colour = %#X\n", d->mp.ceil_col);
		return (1);
	}
	return (0);
}

static void	process_line(t_data *d)
{
	if (!*d->mp.line)
	{
		printf("I want to delete myself\n");
		ft_strdel(&d->mp.line);
	}
	else if (!ft_strncmp(d->mp.line, "R", 1))
		process_reso(d);
	else if (!ft_strncmp(d->mp.line, "NO", 2))
		process_texture(d, "NO");
	else if (!ft_strncmp(d->mp.line, "SO", 2))
		process_texture(d, "SO");
	else if (!ft_strncmp(d->mp.line, "WE", 2))
		process_texture(d, "WE");
	else if (!ft_strncmp(d->mp.line, "EA", 2))
		process_texture(d, "EA");
	else if (!ft_strncmp(d->mp.line, "S ", 2))
		process_texture(d, "SPRITE");
	else if (!ft_strncmp(d->mp.line, "F", 1))
		process_floor_ceil(d, "FLOOR");
	else if (!ft_strncmp(d->mp.line, "C", 1))
		process_floor_ceil(d, "CEIL");
}

void	parse_file(t_data *d, char *filename)
{
	int		fd;
	int		retval;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_handling(OPEN_ERR);
	retval = get_next_line(fd, &d->mp.line);
	error_check(d, retval);
	process_line(d);
	while (retval)
	{
		if (d->mp.line)
			ft_strdel(&d->mp.line);
		retval = get_next_line(fd, &d->mp.line);
		if (error_check(d, retval))
			break ;
		process_line(d);
	}
	if (retval == 0 || !process_map(d, fd, retval))
		flush_data(d, MAP_ERR, 1);
	close(fd);
}
