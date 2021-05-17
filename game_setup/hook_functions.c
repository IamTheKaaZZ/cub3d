/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:38:13 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/17 11:21:02 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_data *d)
{
	printf("current coordinates: %f, %f\n", d->pl.grid.x, d->pl.grid.y);
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

int	*image_data(t_image *i)
{
	return ((int *)mlx_get_data_addr(i->ptr, &i->bpp, &i->line_len, &i->end));
}

void	destroy_image(t_image *i, void *mlx)
{
	if (i->ptr)
	{
		mlx_destroy_image(mlx, i->ptr);
		i->ptr = NULL;
		i->addr = NULL;
	}
}

int	close_window(t_data *d)
{
	destroy_image(&d->m.img, d->m.mlx);
	mlx_destroy_window(d->m.mlx, d->m.win);
	flush_data(d, NO_ERROR, TRUE);
	printf("Destroying the window and exiting game.\n");
	exit(EXIT_SUCCESS);
}