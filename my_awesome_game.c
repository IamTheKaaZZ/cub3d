/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:26:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/14 17:32:38 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh_screen(t_data *d)
{
	draw_ceiling(d);
	draw_floor(d);
	draw_walls(d);
	if (d->mp.tile_size != 0)
	{
		fill_minimap(d);
		refresh_player(d);
	}
	mlx_put_image_to_window(d->m.mlx, d->m.win, d->m.img.ptr, 0, 0);
}

int	render_next_frame(t_data *d)
{
	movement(d);
	cast_rays(d);
	refresh_sprites(d);
	refresh_screen(d);
	return (EXIT_SUCCESS);
}

void	cub3d(char *cubfilename)
{
	t_data	d;

	game_data_init(&d, cubfilename);
	//refresh_screen(&d);
	mlx_hook(d.m.win, 2, 1L<<0, &key_press, &d);
	mlx_hook(d.m.win, 3, 1L<<1, &key_release, &d);
	mlx_hook(d.m.win, 17, 1L<<17, &close_window, &d);
	//render_next_frame(&d);
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
