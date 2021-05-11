/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:32:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 16:34:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	game_data_init(t_data *d)
{
	d->pl.map_pos.x = 0;
	d->pl.map_pos.y = 0;
	d->pl.dir = 0;
	d->pl.angle = 0;
	d->pl.img.ptr = NULL;
	d->pl.ray.ptr = NULL;
	d->txt.n.img = NULL;
	d->txt.n.img_h = 0;
	d->txt.n.img_w = 0;
	d->txt.e.img = NULL;
	d->txt.e.img_h = 0;
	d->txt.e.img_w = 0;
	d->txt.s.img = NULL;
	d->txt.s.img_h = 0;
	d->txt.s.img_w = 0;
	d->txt.w.img = NULL;
	d->txt.w.img_h = 0;
	d->txt.w.img_w = 0;
	d->txt.spr.img = NULL;
	d->txt.spr.img_h = 0;
	d->txt.spr.img_w = 0;
}

void	base_data_init(t_data *d)
{
	d->m.mlx = NULL;
	d->m.win = NULL;
	d->m.win_w = 0;
	d->m.win_h = 0;
	d->mp.line = NULL;
	d->mp.n_text = NULL;
	d->mp.s_text = NULL;
	d->mp.w_text = NULL;
	d->mp.e_text = NULL;
	d->mp.sprite = NULL;
	d->mp.floor_col= -1;
	d->mp.ceil_col= -1;
	d->lst = ft_lstnew(NULL);
	d->mt.maxlen = 0;
	d->mt.height = 0;
	d->mt.matrix = NULL;
	d->key.w = 0;
	d->key.a = 0;
	d->key.s = 0;
	d->key.d = 0;
	d->key.l_arr = 0;
	d->key.r_arr = 0;
	d->key.u_arr = 0;
	d->key.d_arr = 0;
	game_data_init(d);
}
