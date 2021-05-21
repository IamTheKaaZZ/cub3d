/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:33:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 12:09:42 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_matrix(char ***split)
{
	int	i;

	i = 0;
	while ((*split)[i])
		ft_strdel(&(*split)[i++]);
	free(*split);
	*split = NULL;
}

static void	total_flush(t_data *d)
{
	if (d->mp.grid)
		free_matrix(&d->mp.grid);
	if (d->sc.n_text.img.ptr)
		destroy_image(&d->sc.n_text.img, d->m.mlx);
	if (d->sc.s_text.img.ptr)
		destroy_image(&d->sc.s_text.img, d->m.mlx);
	if (d->sc.w_text.img.ptr)
		destroy_image(&d->sc.w_text.img, d->m.mlx);
	if (d->sc.e_text.img.ptr)
		destroy_image(&d->sc.e_text.img, d->m.mlx);
	if (d->sc.sprite.img.ptr)
		destroy_image(&d->sc.sprite.img, d->m.mlx);
	if (d->sc.sprites)
	{
		free(d->sc.sprites);
		d->sc.sprites = NULL;
	}
	if (d->rays.array)
	{
		free(d->rays.array);
		d->rays.array = NULL;
	}
}

void	flush_data(t_data *d, int errnum, t_bool totalclean)
{
	if (d->sc.gnl)
		ft_strdel(&d->sc.gnl);
	if (d->sc.n_text.path)
		ft_strdel(&d->sc.n_text.path);
	if (d->sc.s_text.path)
		ft_strdel(&d->sc.s_text.path);
	if (d->sc.w_text.path)
		ft_strdel(&d->sc.w_text.path);
	if (d->sc.e_text.path)
		ft_strdel(&d->sc.e_text.path);
	if (d->sc.sprite.path)
		ft_strdel(&d->sc.sprite.path);
	if (totalclean == TRUE)
		total_flush(d);
	if (errnum >= 0)
		ft_error_handling(errnum);
}
