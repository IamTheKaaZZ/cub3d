/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:08:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/04 17:13:43 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	add_to_list(t_data *d)
{
	t_list *tmpnew;

	tmpnew = ft_lstnew(ft_strdup(d->mp.line));
	if (!tmpnew)
		return (0);
	ft_lstadd_back(&d->lst, tmpnew);
	ft_strdel(&d->mp.line);
	printf("%s\t%p\n", tmpnew->content, tmpnew);
	return (1);
}

int	process_map(t_data *d, int fd, int retval)
{
	t_list	*head;

	if (!(ft_isspace(*d->mp.line) || *d->mp.line == '1'))
		return (0);
	ft_lstadd_back(&d->lst, ft_lstnew(ft_strdup(d->mp.line)));
	if (!d->lst)
		return (0);
	head = d->lst->next;
	printf("%s\t%p\n", head->content, head);
	ft_strdel(&d->mp.line);
	while (retval)
	{
		retval = get_next_line(fd, &d->mp.line);
		if (!(ft_isspace(*d->mp.line) || d->mp.line[0] == '1'))
			return (0);
		if (!add_to_list(d))
			return (0);
	}
	return (1);
}
