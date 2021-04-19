/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:26:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 17:18:02 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



/*
**	void	*mlx;
**	void	*win_mlx;
**	t_image	img1;
**	t_image	img2;
**	int		colour;
**	mlx = mlx_init();
**	win_mlx = mlx_new_window(mlx, 1920, 1080, "Awesome game dude");
**	img1.ptr = mlx_new_image(mlx, 960, 1080);
**	img1.address = (int *)mlx_get_data_addr(img1.ptr, &img1.bitsperpixel, &img1.line_length, &img1.endian);
**	colour = create_trgb(0, 20, 200, 200);
**	fill_rect(&img1, 960, 1080, colour);
**	img2.ptr = mlx_new_image(mlx, 960, 1080);
**	img2.address = (int *)mlx_get_data_addr(img2.ptr, &img2.bitsperpixel, &img2.line_length, &img2.endian);
**	colour = create_inverse_trgb(colour);
**	fill_rect(&img2, 960, 1080, colour);
**	mlx_put_image_to_window(mlx, win_mlx, img1.ptr, 0, 0);
**	mlx_put_image_to_window(mlx, win_mlx, img2.ptr, 960, 0);
**	mlx_loop(mlx);
**	exit(EXIT_SUCCESS);
*/

int	main(int argc, char **argv)
{

	if (argc < 2)
	{
		ft_error_handling(NOT_ENOUGH_ARGS);
		exit(EXIT_FAILURE);
	}
	else if (argc > 3)
	{
		ft_error_handling(TOO_MANY_ARGS);
		exit(EXIT_FAILURE);
	}
	else if (argc == 3 && !ft_strequal(argv[2], "--save"))
	{
		ft_error_handling(INVALID_FLAG);
		exit(EXIT_FAILURE);
	}
	else
	{
		//Do the cub thing
	}
	exit(EXIT_SUCCESS);
}
