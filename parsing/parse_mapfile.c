/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:16:42 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/04 16:26:00 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	error_check(t_data *d, int retval, char **line)
{
	int	i;

	if (retval < 0)
		flush_data(d, READ_ERR);
	if (retval == 2)
	{
		i = 2;
		while ((*line)[i])
		{
			if (!(ft_ischrinset("./", (*line)[i]) || ft_isalpha((*line)[i])
				|| ft_isspace((*line)[i])))
				flush_data(d, INVALID_PATH_CHR);
			i++;
		}
	}
	if (ft_ischrinset(" \t1", **line) && d->mp.res.x && d->mp.res.y
		&& d->mp.n_text && d->mp.s_text && d->mp.w_text && d->mp.e_text
			&& d->mp.sprite && d->mp.floor_col && d->mp.ceil_col)
		return (1);
	return (0);
}

static void	process_reso(t_data *d, char **line)
{
	char	**resolution;
	int		i;

	i = 1;
	while ((*line)[i])
	{
		if (!(ft_isspace((*line)[i++]) || ft_isdigit((*line)[i++])))
			flush_data(d, RES_ERR);
	}
	resolution = ft_split(*line + 2, ' ');
	d->mp.res.x = ft_atoi(resolution[0]);
	d->mp.res.y = ft_atoi(resolution[1]);
	if (resolution[2] != NULL)
	{
		free_split(resolution);
		flush_data(d, RES_ERR);
	}
	free_split(resolution);
	if (d->mp.res.x > MAXRES_X || d->mp.res.y > MAXRES_Y)
		flush_data(d, RES_OVERFLOW);
	//delete later
	printf("Resolution is %d, %d\n", d->mp.res.x, d->mp.res.y);
}

static int	process_floor_ceil(t_data *d, char **line)
{
	char	**rgb;
	int		i;
	int		col;

	i = 1;
	while ((*line)[i])
	{
		if (!(ft_isspace((*line)[i]) || ft_ischrinset(",", (*line)[i])
			|| ft_isdigit((*line)[i])))
			flush_data(d, RGB_ERR);
		i++;
	}
	rgb = ft_split(*line + 2, ',');
	if (rgb[3] != NULL)
	{
		free_split(rgb);
		flush_data(d, RGB_ERR);
	}
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255
		|| ft_atoi(rgb[2]) > 255)
		flush_data(d, RGB_ERR);
	col = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	printf("RGB = %d, %d, %d\n", ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_split(rgb);
	return (col);
}

static void	process_line(t_data *d, char **line)
{
	if (!**line)
	{
		printf("I want to delete myself\n");
		ft_strdel(line);
	}
	else if (!ft_strncmp(*line, "R", 1))
		process_reso(d, line);
	else if (!ft_strncmp(*line, "NO", 2))
	{
		error_check(d, 2, line);
		d->mp.n_text = ft_strtrim((*line + 2), " ");
		printf("North texture = %s\n", d->mp.n_text);
	}
	else if (!ft_strncmp(*line, "SO", 2))
	{
		error_check(d, 2, line);
		d->mp.s_text = ft_strtrim((*line + 2), " ");
		printf("South texture = %s\n", d->mp.s_text);
	}
	else if (!ft_strncmp(*line, "WE", 2))
	{
		error_check(d, 2, line);
		d->mp.w_text = ft_strtrim((*line + 2), " ");
		printf("West texture = %s\n", d->mp.w_text);
	}
	else if (!ft_strncmp(*line, "EA", 2))
	{
		error_check(d, 2, line);
		d->mp.e_text = ft_strtrim((*line + 2), " ");
		printf("East texture = %s\n", d->mp.e_text);
	}
	else if (!ft_strncmp(*line, "S", 1))
	{
		error_check(d, 2, line);
		d->mp.sprite = ft_strtrim((*line + 1), " ");
		printf("Sprite texture = %s\n", d->mp.sprite);
	}
	else if (!ft_strncmp(*line, "F", 1))
	{
		d->mp.floor_col = process_floor_ceil(d, line);
		printf("Floor colour = %x\n", d->mp.floor_col);
	}
	else if (!ft_strncmp(*line, "C", 1))
	{
		d->mp.ceil_col = process_floor_ceil(d, line);
		printf("Ceiling colour = %x\n", d->mp.ceil_col);
	}
}

void	parse_file(t_data *d, char *filename)
{
	int		fd;
	int		retval;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_handling(OPEN_ERR);
	retval = get_next_line(fd, &d->mp.line);
	error_check(d, retval, &d->mp.line);
	process_line(d, &d->mp.line);
	while (retval)
	{
		if (d->mp.line)
			ft_strdel(&d->mp.line);
		retval = get_next_line(fd, &d->mp.line);
		if (error_check(d, retval, &d->mp.line))
			break ;
		process_line(d, &d->mp.line);
	}
	if (retval == 0 || !process_map(d, fd, retval))
		flush_data(d, MAP_ERR);
	close(fd);
}
