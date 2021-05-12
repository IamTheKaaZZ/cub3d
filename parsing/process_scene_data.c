/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_scene_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:59:47 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 11:40:03 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	process_reso(t_data *d)
{
	char	**resolution;
	int		i;

	i = 1;
	while (d->mp.gnl[i])
	{
		if (!(ft_isspace(d->mp.gnl[i]) || ft_isdigit(d->mp.gnl[i])))
			flush_data(d, RES_ERR, TRUE);
		i++;
	}
	if (d->m.win_w && d->m.win_h)
		flush_data(d, OVERWRITE_ERR, TRUE);
	resolution = ft_split(d->mp.gnl + 2, ' ');
	if (resolution[2] != NULL)
	{
		free_matrix(&resolution);
		flush_data(d, RES_ERR, TRUE);
	}
	d->m.win_w = ft_atoi(resolution[0]);
	d->m.win_h = ft_atoi(resolution[1]);
	if (d->m.win_w > MAXRES_X || d->m.win_h > MAXRES_Y)
	{
		d->m.win_w = MAXRES_X;
		d->m.win_h = MAXRES_Y;
	}
	free_matrix(&resolution);
}

void	process_texture(t_data *d, char *text_name)
{
	int	i;

	i = 2;
	while (d->mp.gnl[i])
	{
		if (!(ft_ischrinset("./-_", d->mp.gnl[i]) || ft_isalpha(d->mp.gnl[i])
				|| ft_isspace(d->mp.gnl[i])))
			flush_data(d, INVALID_PATH_CHR, TRUE);
		i++;
	}
	if (ft_strequal(text_name, "NO") && !d->mp.n_text.path)
		d->mp.n_text.path = ft_strtrim((d->mp.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "SO") && !d->mp.s_text.path)
		d->mp.s_text.path = ft_strtrim((d->mp.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "WE") && !d->mp.w_text.path)
		d->mp.w_text.path = ft_strtrim((d->mp.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "EA") && !d->mp.e_text.path)
		d->mp.e_text.path = ft_strtrim((d->mp.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "SPRITE") && !d->mp.sprite.path)
		d->mp.sprite.path = ft_strtrim((d->mp.gnl + 1), " \n\t\v\f\r");
	else
		flush_data(d, OVERWRITE_ERR, TRUE);
}

static int	process_colours(t_col *col, char **rgb)
{
	if (rgb[3] != NULL)
		return (0);
	col->r = ft_atoi(rgb[0]);
	col->g = ft_atoi(rgb[1]);
	col->b = ft_atoi(rgb[2]);
	if (col->r > 255 || col->r < 0 || col->g > 255 || col->g < 0
		|| col->b > 255 || col->b < 0)
		return (0);
	col->argb = create_trgb(0, col->r, col->g, col->b);
	return (1);
}

void	process_floor_ceil(t_data *d, char *name)
{
	char	**rgb;
	int		i;
	t_col	col;

	if ((ft_strequal(name, "FLOOR") && d->mp.floor_col != -1)
		|| (ft_strequal(name, "CEIL") && d->mp.ceil_col != -1))
		flush_data(d, OVERWRITE_ERR, 1);
	i = 1;
	while (ft_isspace(d->mp.gnl[i]))
		i++;
	while (d->mp.gnl[i])
	{
		if (!(d->mp.gnl[i] == ',' || ft_isdigit(d->mp.gnl[i]))
			|| (d->mp.gnl[i] == ',' && (!ft_isdigit(d->mp.gnl[i - 1])
					|| !ft_isdigit(d->mp.gnl[i + 1]))))
			flush_data(d, RGB_ERR, TRUE);
		i++;
	}
	rgb = ft_split(d->mp.gnl + 2, ',');
	if (!process_colours(&col, rgb))
	{
		free_matrix(&rgb);
		flush_data(d, RGB_ERR, TRUE);
	}
	if (ft_strequal(name, "FLOOR"))
		d->mp.floor_col = col.argb;
	else if (ft_strequal(name, "CEIL"))
		d->mp.ceil_col = col.argb;
	printf("RGB = %d, %d, %d\n", col.r, col.g, col.b);
	free_matrix(&rgb);
}
