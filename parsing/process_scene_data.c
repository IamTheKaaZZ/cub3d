/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_scene_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:59:47 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 15:48:08 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	process_reso(t_data *d)
{
	char	**resolution;
	int		i;

	i = 1;
	while (d->sc.gnl[i])
	{
		if (!(ft_isspace(d->sc.gnl[i]) || ft_isdigit(d->sc.gnl[i])))
			flush_data(d, RES_ERR, TRUE);
		i++;
	}
	if (d->m.win_w && d->m.win_h)
		flush_data(d, OVERWRITE_ERR, TRUE);
	resolution = ft_split(d->sc.gnl + 2, ' ');
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
	while (d->sc.gnl[i])
	{
		if (!(ft_ischrinset("./-_", d->sc.gnl[i]) || ft_isalpha(d->sc.gnl[i])
				|| ft_isspace(d->sc.gnl[i])))
			flush_data(d, INVALID_PATH_CHR, TRUE);
		i++;
	}
	if (ft_strequal(text_name, "NO") && !d->sc.n_text.path)
		d->sc.n_text.path = ft_strtrim((d->sc.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "SO") && !d->sc.s_text.path)
		d->sc.s_text.path = ft_strtrim((d->sc.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "WE") && !d->sc.w_text.path)
		d->sc.w_text.path = ft_strtrim((d->sc.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "EA") && !d->sc.e_text.path)
		d->sc.e_text.path = ft_strtrim((d->sc.gnl + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "SPRITE") && !d->sc.sprite.path)
		d->sc.sprite.path = ft_strtrim((d->sc.gnl + 1), " \n\t\v\f\r");
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

	if ((ft_strequal(name, "FLOOR") && d->sc.floor_col != -1)
		|| (ft_strequal(name, "CEIL") && d->sc.ceil_col != -1))
		flush_data(d, OVERWRITE_ERR, 1);
	i = 1;
	while (ft_isspace(d->sc.gnl[i]))
		i++;
	while (d->sc.gnl[i])
	{
		if (!(d->sc.gnl[i] == ',' || ft_isdigit(d->sc.gnl[i]))
			|| (d->sc.gnl[i] == ',' && (!ft_isdigit(d->sc.gnl[i - 1])
					|| !ft_isdigit(d->sc.gnl[i + 1]))))
			flush_data(d, RGB_ERR, TRUE);
		i++;
	}
	rgb = ft_split(d->sc.gnl + 2, ',');
	if (!process_colours(&col, rgb))
	{
		free_matrix(&rgb);
		flush_data(d, RGB_ERR, TRUE);
	}
	if (ft_strequal(name, "FLOOR"))
		d->sc.floor_col = col.argb;
	else if (ft_strequal(name, "CEIL"))
		d->sc.ceil_col = col.argb;
	printf("RGB = %d, %d, %d\n", col.r, col.g, col.b);
	free_matrix(&rgb);
}
