/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:32:58 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 17:32:57 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	game_data_init(t_data *d)
{
	d->pl.grid_pos.x = 0;
	d->pl.grid_pos.y = 0;
	d->pl.dir = 0;
	d->pl.angle = 0;
	d->sc.n_text.data.img = NULL;
	d->sc.n_text.data.img_h = 0;
	d->sc.n_text.data.img_w = 0;
	d->sc.e_text.data.img = NULL;
	d->sc.e_text.data.img_h = 0;
	d->sc.e_text.data.img_w = 0;
	d->sc.s_text.data.img = NULL;
	d->sc.s_text.data.img_h = 0;
	d->sc.s_text.data.img_w = 0;
	d->sc.w_text.data.img = NULL;
	d->sc.w_text.data.img_h = 0;
	d->sc.w_text.data.img_w = 0;
	d->sc.sprite.data.img = NULL;
	d->sc.sprite.data.img_h = 0;
	d->sc.sprite.data.img_w = 0;
	d->sc.sprite_count = 0;
}

void	base_data_init(t_data *d)
{
	d->m.mlx = NULL;
	d->m.win = NULL;
	d->m.win_w = 0;
	d->m.win_h = 0;
	d->sc.gnl = NULL;
	d->sc.n_text.path = NULL;
	d->sc.s_text.path = NULL;
	d->sc.w_text.path = NULL;
	d->sc.e_text.path = NULL;
	d->sc.sprite.path = NULL;
	d->sc.floor_col= -1;
	d->sc.ceil_col= -1;
	d->lst = ft_lstnew(NULL);
	d->mp.max_x = 0;
	d->mp.max_y = 0;
	d->mp.grid = NULL;
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
