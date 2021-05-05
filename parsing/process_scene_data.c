/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_scene_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:59:47 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/05 17:43:09 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	process_reso(t_data *d)
{
	char	**resolution;
	int		i;

	i = 1;
	while (d->mp.line[i])
	{
		if (!(ft_isspace(d->mp.line[i]) || ft_isdigit(d->mp.line[i])))
			flush_data(d, RES_ERR);
		i++;
	}
	if (d->mp.res.x && d->mp.res.y)
		flush_data(d, OVERWRITE_ERR);
	resolution = ft_split(d->mp.line + 2, ' ');
	if (resolution[2] != NULL)
	{
		free_split(&resolution);
		flush_data(d, RES_ERR);
	}
	d->mp.res.x = ft_atoi(resolution[0]);
	d->mp.res.y = ft_atoi(resolution[1]);
	if (d->mp.res.x > MAXRES_X || d->mp.res.y > MAXRES_Y)
	{
		d->mp.res.x = MAXRES_X;
		d->mp.res.y = MAXRES_Y;
	}
	free_split(&resolution);
}

void	process_texture(t_data *d, char *text_name)
{
	int	i;

	i = 2;
	while (d->mp.line[i])
	{
		if (!(ft_ischrinset("./", d->mp.line[i]) || ft_isalpha(d->mp.line[i])
				|| ft_isspace(d->mp.line[i])))
			flush_data(d, INVALID_PATH_CHR);
		i++;
	}
	if (ft_strequal(text_name, "NO") && !d->mp.n_text)
		d->mp.n_text = ft_strtrim((d->mp.line + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "SO") && !d->mp.s_text)
		d->mp.s_text = ft_strtrim((d->mp.line + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "WE") && !d->mp.w_text)
		d->mp.w_text = ft_strtrim((d->mp.line + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "EA") && !d->mp.e_text)
		d->mp.e_text = ft_strtrim((d->mp.line + 2), " \n\t\v\f\r");
	else if (ft_strequal(text_name, "SPRITE") && !d->mp.sprite)
		d->mp.sprite = ft_strtrim((d->mp.line + 1), " \n\t\v\f\r");
	else
		flush_data(d, OVERWRITE_ERR);
}

void	process_floor_ceil(t_data *d, char *name)
{
	char	**rgb;
	int		i;
	int		col;

	if ((ft_strequal(name, "FLOOR") && d->mp.floor_col != -1)
		|| (ft_strequal(name, "CEIL") && d->mp.ceil_col != -1))
		flush_data(d, OVERWRITE_ERR);
	i = 1;
	while (ft_isspace(d->mp.line[i]))
		i++;
	while (d->mp.line[i])
	{
		if (!(d->mp.line[i] == ',' || ft_isdigit(d->mp.line[i]))
			|| (d->mp.line[i] == ',' && (!ft_isdigit(d->mp.line[i - 1])
					|| !ft_isdigit(d->mp.line[i + 1]))))
			flush_data(d, RGB_ERR);
		i++;
	}
	rgb = ft_split(d->mp.line + 2, ',');
	if (rgb[3] != NULL || ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255
		|| ft_atoi(rgb[2]) > 255)
	{
		free_split(&rgb);
		flush_data(d, RGB_ERR);
	}
	col = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	if (ft_strequal(name, "FLOOR"))
		d->mp.floor_col = col;
	else if (ft_strequal(name, "CEIL"))
		d->mp.ceil_col = col;
	printf("RGB = %d, %d, %d\n", ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_split(&rgb);
}
