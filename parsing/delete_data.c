/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:33:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 11:39:12 by bcosters         ###   ########.fr       */
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

void	flush_data(t_data *d, int errnum, t_bool totalclean)
{
	if (d->mp.gnl)
		ft_strdel(&d->mp.gnl);
	if (d->mp.n_text.path)
		ft_strdel(&d->mp.n_text.path);
	if (d->mp.s_text.path)
		ft_strdel(&d->mp.s_text.path);
	if (d->mp.w_text.path)
		ft_strdel(&d->mp.w_text.path);
	if (d->mp.e_text.path)
		ft_strdel(&d->mp.e_text.path);
	if (d->mp.sprite.path)
		ft_strdel(&d->mp.sprite.path);
	if (d->lst)
		ft_lstmemdel_clear(&d->lst, ft_memdel);
	if (d->mt.grid && totalclean)
		free_matrix(&d->mt.grid);
	if (errnum >= 0)
		ft_error_handling(errnum);
}
