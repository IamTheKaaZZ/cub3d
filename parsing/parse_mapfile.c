/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:16:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 15:46:43 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	error_check(t_data *d, int retval)
{
	if (retval < 0)
		flush_data(d, READ_ERR, TRUE);
	if (ft_ischrinset(" \t1", *d->sc.gnl) && d->m.win_w && d->m.win_h
		&& d->sc.n_text.path && d->sc.s_text.path && d->sc.w_text.path
		&& d->sc.e_text.path && d->sc.sprite.path && d->sc.floor_col
		&& d->sc.ceil_col)
	{
		printf("Resolution is %d, %d\n", d->m.win_w, d->m.win_h);
		printf("North texture = %s\n", d->sc.n_text.path);
		printf("South texture = %s\n", d->sc.s_text.path);
		printf("West texture = %s\n", d->sc.w_text.path);
		printf("East texture = %s\n", d->sc.e_text.path);
		printf("Sprite texture = %s\n", d->sc.sprite.path);
		printf("Floor colour = 0X00%X\n", d->sc.floor_col);
		printf("Ceiling colour = 0X00%X\n", d->sc.ceil_col);
		return (1);
	}
	return (0);
}

static void	process_gnl(t_data *d)
{
	if (!*d->sc.gnl)
	{
		printf("I want to delete myself\n");
		ft_strdel(&d->sc.gnl);
	}
	else if (!ft_strncmp(d->sc.gnl, "R", 1))
		process_reso(d);
	else if (!ft_strncmp(d->sc.gnl, "NO", 2))
		process_texture(d, "NO");
	else if (!ft_strncmp(d->sc.gnl, "SO", 2))
		process_texture(d, "SO");
	else if (!ft_strncmp(d->sc.gnl, "WE", 2))
		process_texture(d, "WE");
	else if (!ft_strncmp(d->sc.gnl, "EA", 2))
		process_texture(d, "EA");
	else if (!ft_strncmp(d->sc.gnl, "S ", 2))
		process_texture(d, "SPRITE");
	else if (!ft_strncmp(d->sc.gnl, "F", 1))
		process_floor_ceil(d, "FLOOR");
	else if (!ft_strncmp(d->sc.gnl, "C", 1))
		process_floor_ceil(d, "CEIL");
}

void	parse_file(t_data *d, char *filename)
{
	int		fd;
	int		retval;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_handling(OPEN_ERR);
	retval = get_next_line(fd, &d->sc.gnl);
	error_check(d, retval);
	process_gnl(d);
	while (retval)
	{
		if (d->sc.gnl)
			ft_strdel(&d->sc.gnl);
		retval = get_next_line(fd, &d->sc.gnl);
		if (error_check(d, retval))
			break ;
		process_gnl(d);
	}
	if (retval == 0 || !process_map(d, fd, retval))
		flush_data(d, MAP_ERR, TRUE);
	close(fd);
}
