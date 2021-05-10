/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:26:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/10 17:03:23 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*image_data(t_image *i)
{
	return ((int *)mlx_get_data_addr(i->ptr, &i->bpp, &i->line_len, &i->end));
}

void	init_bg(t_data *d)
{
	d->bg.map2d.ptr = mlx_new_image(d->m.mlx, (d->m.win_w / 2), d->m.win_h);
	d->bg.map2d.addr = image_data(&d->bg.map2d);
	d->bg.col1 = create_trgb(0, 20, 200, 200);
	d->bg.map3d.ptr = mlx_new_image(d->m.mlx, (d->m.win_w / 2), d->m.win_h);
	d->bg.map3d.addr = image_data(&d->bg.map3d);
	d->bg.col2 = create_inverse_trgb(d->bg.col1);
	draw_2d_map(d);
	//fill_rect(&d->bg.map2d, d->m.win_w / 2, d->m.win_h, d->bg.col1);
	fill_rect(&d->bg.map3d, d->m.win_w / 2, d->m.win_h, d->bg.col2);
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->bg.map2d.ptr, 0, 0);
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->bg.map3d.ptr, (d->m.win_w / 2), 0);
	//mlx_put_image_to_window(d->m.mlx, d->m.win, d->txt.w.img, 500, 500);
}

void	init_circle(t_data *d)
{
	d->pl.img.ptr = mlx_new_image(d->m.mlx, 40, 40);
	d->pl.img.addr = image_data(&d->pl.img);
	fill_circle(&d->pl.img, 20, create_trgb(0, 61, 252, 3));
	mlx_put_image_to_window(d->m.mlx, d->m.win,
		d->pl.img.ptr, d->pl.pos.x, d->pl.pos.y);
}

int	close_window(t_data *d)
{
	mlx_destroy_window(d->m.mlx, d->m.win);
	flush_data(d, -1, 1);
	printf("Destroying the window and exiting game.\n");
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_data *d)
{
	printf("current coordinates: %f, %f\n", d->pl.pos.x, d->pl.pos.y);
	printf("You pressed this key: %d\n", keycode);
	if (keycode == ESCAPE_KEY)
		close_window(d);
	if (keycode == W_KEY)
		d->key.w = 1;
	if (keycode == S_KEY)
		d->key.s = 1;
	if (keycode == A_KEY)
		d->key.a = 1;
	if (keycode == D_KEY)
		d->key.d = 1;
	if (keycode == LEFT_ARR_KEY)
		d->key.l_arr = 1;
	if (keycode == RIGHT_ARR_KEY)
		d->key.r_arr = 1;
	if (keycode == UP_ARR_KEY)
		d->key.u_arr = 1;
	if (keycode == DOWN_ARR_KEY)
		d->key.d_arr = 1;
	return (keycode);
}

int	key_release(int keycode, t_data *d)
{
	printf("You pressed this key: %d\n", keycode);
	if (keycode == W_KEY)
		d->key.w = 0;
	if (keycode == S_KEY)
		d->key.s = 0;
	if (keycode == A_KEY)
		d->key.a = 0;
	if (keycode == D_KEY)
		d->key.d = 0;
	if (keycode == LEFT_ARR_KEY)
		d->key.l_arr = 0;
	if (keycode == RIGHT_ARR_KEY)
		d->key.r_arr = 0;
	if (keycode == UP_ARR_KEY)
		d->key.u_arr = 0;
	if (keycode == DOWN_ARR_KEY)
		d->key.d_arr = 0;
	return (keycode);
}

void	destroy_image(t_data *d, void *iptr, void *addr)
{
	if (iptr)
	{
		mlx_destroy_image(d->m.mlx, iptr);
		iptr = NULL;
		addr = NULL;
	}
}

void	movement(t_data *d)
{

	if (d->key.w && d->pl.pos.y >= 0)
		d->pl.pos.y -= 4;
	if (d->key.s && d->pl.pos.y <= d->m.win_h)
		d->pl.pos.y += 4;
	if (d->key.a && d->pl.pos.x >= 0)
		d->pl.pos.x -= 4;
	if (d->key.d && d->pl.pos.x <= d->m.win_w)
		d->pl.pos.x += 4;
	destroy_image(d, d->pl.img.ptr, d->pl.img.addr);
	destroy_image(d, d->bg.map2d.ptr, d->bg.map2d.addr);
	destroy_image(d, d->bg.map3d.ptr, d->bg.map3d.addr);
	init_bg(d);
	init_circle(d);
}

int	render_next_frame(t_data *d)
{
	movement(d);
	return (EXIT_SUCCESS);
}

void	game_data_init(t_data *d)
{
	d->pl.pos.x = 0;
	d->pl.pos.y = 0;
	d->pl.dir = 0;
	d->pl.img.ptr = NULL;
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

void	cub3d(char *cubfilename)
{
	t_data	d;

	base_data_init(&d);
	d.m.mlx = mlx_init();
	parse_file(&d, cubfilename);

	d.m.win = mlx_new_window(d.m.mlx, d.m.win_w, d.m.win_h, "This game is pretty awesome");

	init_bg(&d);
	init_circle(&d);
	mlx_hook(d.m.win, 2, 1L<<0, key_press, &d);
	mlx_hook(d.m.win, 3, 1L<<1, key_release, &d);
	mlx_hook(d.m.win, 17, 1L<<17, close_window, &d);

	mlx_loop_hook(d.m.mlx, render_next_frame, &d);
	mlx_loop(d.m.mlx);
}

int	main(int argc, char **argv)
{
	char	*errortest;

	if (argc < 2)
		ft_error_handling(NOT_ENOUGH_ARGS);
	else if (argc > 3)
		ft_error_handling(TOO_MANY_ARGS);
	else if (argc == 3 && !ft_strequal(argv[2], "--save"))
		ft_error_handling(INVALID_FLAG);
	else
	{
		errortest = argv[1];
		ft_str_rev(errortest);
		if (ft_strncmp(errortest, "buc.", 4))
			ft_error_handling(NO_CUB_FILE_TYPE);
		ft_str_rev(errortest);
		cub3d(argv[1]);
	}
	exit(EXIT_SUCCESS);
}
