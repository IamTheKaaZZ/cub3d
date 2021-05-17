/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:09:10 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 11:21:28 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	data_init_two(t_data *d)
{
	d->pl.grid.x = 0;
	d->pl.grid.y = 0;
	d->mp.player_dir = 0;
	d->pl.angle = 0;
	d->sc.n_text.img.ptr = NULL;
	d->sc.n_text.img_h = 0;
	d->sc.n_text.img_w = 0;
	d->sc.e_text.img.ptr = NULL;
	d->sc.e_text.img_h = 0;
	d->sc.e_text.img_w = 0;
	d->sc.s_text.img.ptr = NULL;
	d->sc.s_text.img_h = 0;
	d->sc.s_text.img_w = 0;
	d->sc.w_text.img.ptr = NULL;
	d->sc.w_text.img_h = 0;
	d->sc.w_text.img_w = 0;
	d->sc.sprite.img.ptr = NULL;
	d->sc.sprite.img_h = 0;
	d->sc.sprite.img_w = 0;
	d->sc.sprite_count = 0;
	d->sc.sprites = NULL;
}

static void	data_init_one(t_data *d)
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
}

void	game_data_init(t_data *d, char *cubfilename)
{
	data_init_one(d);
	data_init_two(d);
	d->m.mlx = mlx_init();
	parse_file(d, cubfilename);
	init_texts_rays(d);
	init_sprites(d);
	d->m.win = mlx_new_window(d->m.mlx, d->m.win_w, d->m.win_h, "This game is pretty awesome");
	d->m.img.ptr = mlx_new_image(d->m.mlx, d->m.win_w, d->m.win_h);
	d->m.img.addr = image_data(&d->m.img);
}
