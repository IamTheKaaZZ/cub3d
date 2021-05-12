/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:08:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/12 14:40:32 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*tab_realloc(char *line)
{
	int		i;
	int		tabcount;
	char	*result;

	tabcount = 0;
	i = 0;
	while (line[i])
	{
		if (line[i++] == '\t')
			tabcount++;
	}
	result = ft_calloc(ft_strlen(line) + 1 + tabcount * 3, sizeof(char));
	if (result == NULL)
		return (NULL);
	return (result);
}

static char	*tab_to_spaces(char *line)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	result = tab_realloc(line);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			k = 4;
			while (k--)
				result[j++] = ' ';
		}
		else
			result[j++] = line[i];
		i++;
	}
	ft_strdel(&line);
	return (result);
}

static int	add_to_list(t_data *d)
{
	t_list *tmpnew;

	d->mp.gnl = tab_to_spaces(d->mp.gnl);
	if ((int)ft_strlen(d->mp.gnl) > d->mt.max_x)
		d->mt.max_x = ft_strlen(d->mp.gnl);
	tmpnew = ft_lstnew(ft_strdup(d->mp.gnl));
	if (!tmpnew)
		return (0);
	ft_lstadd_back(&d->lst, tmpnew);
	ft_strdel(&d->mp.gnl);
	return (1);
}

int	process_map(t_data *d, int fd, int retval)
{
	if (!(ft_isspace(*d->mp.gnl) || *d->mp.gnl == '1'))
		return (0);
	d->mp.gnl = tab_to_spaces(d->mp.gnl);
	d->mt.max_x = ft_strlen(d->mp.gnl);
	ft_lstadd_back(&d->lst, ft_lstnew(ft_strdup(d->mp.gnl)));
	if (!d->lst->next)
		return (0);
	ft_strdel(&d->mp.gnl);
	while (retval)
	{
		retval = get_next_line(fd, &d->mp.gnl);
		if (!(ft_isspace(*d->mp.gnl) || d->mp.gnl[0] == '1'))
			return (0);
		if (!add_to_list(d))
			return (0);
	}
	d->mt.max_y = ft_lstsize(d->lst) - 1;
	//
	printf("maxlen = %d\n", d->mt.max_x);
	printf("list size = %d\n", d->mt.max_y);
	//
	if (!create_matrix(d))
		return (0);
	return (1);
}
