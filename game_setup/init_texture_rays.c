/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:26:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 14:17:10 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_text_data(t_text *text)
{
	text->img.addr = image_data(&text->img);
}

void	init_texts_rays(t_data *d)
{
	get_text_data(&d->sc.n_text);
	get_text_data(&d->sc.s_text);
	get_text_data(&d->sc.e_text);
	get_text_data(&d->sc.w_text);
	get_text_data(&d->sc.sprite);
	d->rays.array = (t_ray *)malloc(d->m.win_w * sizeof(t_ray));
	if (!d->rays.array)
		flush_data(d, DATA_ERR, TRUE);
	d->rays.fov = degree_to_radian(FOV);
	d->rays.dist_proj_plane = (d->m.win_w / 2) / tan(d->rays.fov / 2);
}
