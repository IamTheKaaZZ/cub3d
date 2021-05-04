/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:33:36 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/04 17:13:26 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		ft_strdel(&split[i++]);
	free(split);
	split = NULL;
}

void	flush_data(t_data *d, int errnum)
{
	if (d->mp.line)
		ft_strdel(&d->mp.line);
	if (d->mp.n_text)
		ft_strdel(&d->mp.n_text);
	if (d->mp.s_text)
		ft_strdel(&d->mp.s_text);
	if (d->mp.w_text)
		ft_strdel(&d->mp.w_text);
	if (d->mp.e_text)
		ft_strdel(&d->mp.e_text);
	if (d->mp.sprite)
		ft_strdel(&d->mp.sprite);
	if (d->lst)
		ft_lstclear(&d->lst, free);
	if (errnum >= 0)
		ft_error_handling(errnum);
}
