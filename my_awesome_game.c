/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:26:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 17:13:04 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh_screen(t_data *d)
{
	t_rect	bg;

	bg.x = 0;
	bg.y = 0;
	bg.height = d->m.win_h;
	bg.width = d->m.win_w;
	bg.fill_col = d->mp.ceil_col;
	bg.border_width = 0;
	fill_rect(&bg, d->m.img.addr, d->m.win_w);
	fill_minimap(d);
	refresh_player(d);
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->m.img.ptr, 0, 0);
	mlx_string_put(d->m.mlx, d->m.win, 100, 600, create_trgb(0, 255, 255, 255), "Text here");
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->mp.sprite.data.img, 600, 500);
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
	d.m.img.ptr = mlx_new_image(d.m.mlx, d.m.win_w, d.m.win_h);
	d.m.img.addr = image_data(&d.m.img);
	refresh_screen(&d);
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
