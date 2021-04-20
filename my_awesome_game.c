/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:26:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/20 17:25:22 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*image_data(t_image *i)
{
	return ((int *)mlx_get_data_addr(i->ptr, &i->bpp, &i->line_len, &i->end));
}

void	init_bg(t_data *d)
{
	d->bg.bg1.ptr = mlx_new_image(d->m.mlx, 960, 1080);
	d->bg.bg1.addr = image_data(&d->bg.bg1);
	d->bg.colour = create_trgb(0, 20, 200, 200);
	fill_rect(&d->bg.bg1, 960, 1080, d->bg.colour);
	d->bg.bg2.ptr = mlx_new_image(d->m.mlx, 960, 1080);
	d->bg.bg2.addr = image_data(&d->bg.bg2);
	d->bg.colour = create_inverse_trgb(d->bg.colour);
	fill_rect(&d->bg.bg2, 960, 1080, d->bg.colour);
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->bg.bg1.ptr, 0, 0);
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->bg.bg2.ptr, 960, 0);
}

void	init_circle(t_data *d)
{
	d->i.ptr = mlx_new_image(d->m.mlx, 50, 50);
	d->i.addr = image_data(&d->i);
	fill_circle(&d->i, 25, create_trgb(0, 61, 252, 3));
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->i.ptr, d->p.x, d->p.y);
}

int	close_window(t_data *d)
{
	mlx_destroy_window(d->m.mlx, d->m.win);
	printf("Destroying the window and exiting game.\n");
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *d)
{
	printf("You pressed this key: %d\n", keycode);
	printf("current coordinates: %d, %d\n", d->p.x, d->p.y);
	if (keycode == ESCAPE_KEY)
		close_window(d);
	if (keycode == W_KEY || keycode == S_KEY
		|| keycode == A_KEY || keycode == D_KEY)
	{
		if (keycode == W_KEY && d->p.y >= 0)
			d->p.y -= 4;
		if (keycode == S_KEY && d->p.y <= d->m.win_h)
			d->p.y += 4;
		if (keycode == A_KEY && d->p.x >= 0)
			d->p.x -= 4;
		if (keycode == D_KEY && d->p.x <= d->m.win_w)
			d->p.x += 4;
	}
	if (d->i.ptr)
	{
		mlx_destroy_image(d->m.mlx, d->i.ptr);
		d->i.ptr = NULL;
		d->i.addr = NULL;
	}
	if (d->bg.bg1.ptr)
	{
		mlx_destroy_image(d->m.mlx, d->bg.bg1.ptr);
		mlx_destroy_image(d->m.mlx, d->bg.bg2.ptr);
		d->bg.bg1.ptr = NULL;
		d->bg.bg1.addr = NULL;
		d->bg.bg2.ptr = NULL;
		d->bg.bg2.addr = NULL;
	}
	init_bg(d);
	init_circle(d);
	return (keycode);
}

int	render_next_frame(t_data *d)
{
	mlx_hook(d->m.win, 2, 1L<<0, key_hook, d);
	mlx_hook(d->m.win, 17, 1L<<17, close_window, d);
	return (EXIT_SUCCESS);
}


void	cub3d(char *cubfilename)
{
	t_data	d;

	d.p.x = 0;
	d.p.y = 0;
	d.i.ptr = NULL;

	d.m.win_h = 1080;
	d.m.win_w = 1920;
	d.m.mlx = mlx_init();
	d.m.win = mlx_new_window(d.m.mlx, d.m.win_w, d.m.win_h, cubfilename);

	init_bg(&d);
	init_circle(&d);

	mlx_loop_hook(d.m.mlx, render_next_frame, &d);
	mlx_loop(d.m.mlx);
}

/*
**	void	*mlx;
**	void	*win_mlx;
**	t_image	bg1;
**	t_image	bg2;
**	int		colour;
**	mlx = mlx_init();
**	win_mlx = mlx_new_window(mlx, 1920, 1080, "Awesome game dude");
**	bg1.ptr = mlx_new_image(mlx, 960, 1080);
**	bg1.address = (int *)mlx_get_data_addr(bg1.ptr, &bg1.bitsperpixel, &bg1.line_length, &bg1.endian);
**	colour = create_trgb(0, 20, 200, 200);
**	fill_rect(&bg1, 960, 1080, colour);
**	bg2.ptr = mlx_new_image(mlx, 960, 1080);
**	bg2.address = (int *)mlx_get_data_addr(bg2.ptr, &bg2.bitsperpixel, &bg2.line_length, &bg2.endian);
**	colour = create_inverse_trgb(colour);
**	fill_rect(&bg2, 960, 1080, colour);
**	mlx_put_image_to_window(mlx, win_mlx, bg1.ptr, 0, 0);
**	mlx_put_image_to_window(mlx, win_mlx, bg2.ptr, 960, 0);
**	mlx_loop(mlx);
**	exit(EXIT_SUCCESS);
*/

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
