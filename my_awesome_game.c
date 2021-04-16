/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:26:44 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/16 17:22:01 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	fill_square(t_image *img, int height, int width, int colour)
{
	int	h;
	int	w;

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			img->address[h * 3 + w] = colour;
			w++;
		}

		h++;
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win_mlx;
	t_image	img;
	int		colour;

	if (argc > 2)
	{
		ft_putstr_fd("Error\nToo many arguments.\nUSAGE: NO arguments OR --save\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc == 2 && !ft_strequal(argv[1], "--save"))
	{
		ft_putstr_fd("Error\nInvalid flag.\nUSAGE: NO arguments OR --save\n", 2);
		exit(EXIT_FAILURE);
	}
	mlx = mlx_init();
	win_mlx = mlx_new_window(mlx, 1920, 1020, "Awesome game dude");

	img.ptr = mlx_new_image(mlx, 5, 5);
	img.address = mlx_get_data_addr(img.ptr, &img.bitsperpixel, &img.line_length, &img.endian);
	colour = create_trgb(0, 255, 202, 65);
	fill_square(&img, 5, 5, colour);
	mlx_put_image_to_window(mlx, win_mlx, img.ptr, 0, 0);
	mlx_loop(mlx);
	exit(EXIT_SUCCESS);
}
