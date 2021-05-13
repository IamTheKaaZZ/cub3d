/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:33:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/13 15:46:15 by bcosters         ###   ########.fr       */
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
	if (d->lst)
		ft_lstmemdel_clear(&d->lst, ft_memdel);
	if (d->mp.grid && totalclean)
		free_matrix(&d->mp.grid);
	if (errnum >= 0)
		ft_error_handling(errnum);
}
