/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:32:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 15:56:29 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	game_data_init(t_data *d)
{
	d->pl.grid_pos.x = 0;
	d->pl.grid_pos.y = 0;
	d->pl.dir = 0;
	d->pl.angle = 0;
	d->mp.n_text.data.img = NULL;
	d->mp.n_text.data.img_h = 0;
	d->mp.n_text.data.img_w = 0;
	d->mp.e_text.data.img = NULL;
	d->mp.e_text.data.img_h = 0;
	d->mp.e_text.data.img_w = 0;
	d->mp.s_text.data.img = NULL;
	d->mp.s_text.data.img_h = 0;
	d->mp.s_text.data.img_w = 0;
	d->mp.w_text.data.img = NULL;
	d->mp.w_text.data.img_h = 0;
	d->mp.w_text.data.img_w = 0;
	d->mp.sprite.data.img = NULL;
	d->mp.sprite.data.img_h = 0;
	d->mp.sprite.data.img_w = 0;
}

void	base_data_init(t_data *d)
{
	d->m.mlx = NULL;
	d->m.win = NULL;
	d->m.win_w = 0;
	d->m.win_h = 0;
	d->mp.gnl = NULL;
	d->mp.n_text.path = NULL;
	d->mp.s_text.path = NULL;
	d->mp.w_text.path = NULL;
	d->mp.e_text.path = NULL;
	d->mp.sprite.path = NULL;
	d->mp.floor_col= -1;
	d->mp.ceil_col= -1;
	d->lst = ft_lstnew(NULL);
	d->mt.max_x = 0;
	d->mt.max_y = 0;
	d->mt.grid = NULL;
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
