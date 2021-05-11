/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:26:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/11 17:25:40 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_bg(t_data *d)
{
	d->bg.map2d.ptr = mlx_new_image(d->m.mlx, (d->m.win_w / 2), d->m.win_h);
	d->bg.map2d.addr = image_data(&d->bg.map2d);
	d->bg.col1 = create_trgb(0, 20, 200, 200);
	d->bg.map3d.ptr = mlx_new_image(d->m.mlx, (d->m.win_w / 2), d->m.win_h);
	d->bg.map3d.addr = image_data(&d->bg.map3d);
	d->bg.col2 = create_inverse_trgb(d->bg.col1);
	draw_2d_map(d);
	fill_rect(&d->bg.map3d, d->m.win_w / 2, d->m.win_h, d->bg.col2);
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->bg.map2d.ptr, 0, 0);
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->bg.map3d.ptr, (d->mt.cub_size * d->mt.maxlen + 1), 0);
	mlx_string_put(d->m.mlx, d->m.win, 100, 600, create_trgb(0, 255, 255, 255), "Text here");
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->txt.spr.img, 600, 500);
}

void	init_player(t_data *d)
{
	d->pl.img.ptr = mlx_new_image(d->m.mlx, 10, 10);
	d->pl.img.addr = image_data(&d->pl.img);
	fill_rect(&d->pl.img, 10, 10, create_trgb(255, 0, 0, 0));
	fill_circle(&d->pl.img, 4, create_trgb(0, 61, 252, 3));
	mlx_put_image_to_window(d->m.mlx, d->m.win,
		d->pl.img.ptr, d->pl.scr_pos.x, d->pl.scr_pos.y);
	d->pl.ray.ptr = mlx_new_image(d->m.mlx, 20, 20);
	d->pl.ray.addr = image_data(&d->pl.ray);
	draw_ray(d, 8, create_trgb(0, 61, 252, 3));
}

int	render_next_frame(t_data *d)
{
	movement(d);
	return (EXIT_SUCCESS);
}

void	cub3d(char *cubfilename)
{
	t_data	d;

	base_data_init(&d);
	d.m.mlx = mlx_init();
	parse_file(&d, cubfilename);
	d.m.win = mlx_new_window(d.m.mlx, d.m.win_w, d.m.win_h, "This game is pretty awesome");
	init_bg(&d);
	init_player(&d);
	mlx_hook(d.m.win, 2, 1L<<0, &key_press, &d);
	mlx_hook(d.m.win, 3, 1L<<1, &key_release, &d);
	mlx_hook(d.m.win, 17, 1L<<17, &close_window, &d);
	mlx_loop_hook(d.m.mlx, &render_next_frame, &d);
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
