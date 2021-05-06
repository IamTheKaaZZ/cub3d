/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:08:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/06 10:55:21 by bcosters         ###   ########.fr       */
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

	d->mp.line = tab_to_spaces(d->mp.line);
	if (ft_strlen(d->mp.line) > d->mt.maxlen)
		d->mt.maxlen = ft_strlen(d->mp.line);
	tmpnew = ft_lstnew(ft_strdup(d->mp.line));
	if (!tmpnew)
		return (0);
	ft_lstadd_back(&d->lst, tmpnew);
	ft_strdel(&d->mp.line);
	return (1);
}

int	process_map(t_data *d, int fd, int retval)
{
	if (!(ft_isspace(*d->mp.line) || *d->mp.line == '1'))
		return (0);
	d->mp.line = tab_to_spaces(d->mp.line);
	d->mt.maxlen = ft_strlen(d->mp.line);
	ft_lstadd_back(&d->lst, ft_lstnew(ft_strdup(d->mp.line)));
	if (!d->lst->next)
		return (0);
	ft_strdel(&d->mp.line);
	while (retval)
	{
		retval = get_next_line(fd, &d->mp.line);
		if (!(ft_isspace(*d->mp.line) || d->mp.line[0] == '1'))
			return (0);
		if (!add_to_list(d))
			return (0);
	}
	d->mt.height = ft_lstsize(d->lst) - 1;
	//
	printf("maxlen = %zu\n", d->mt.maxlen);
	printf("list size = %zu\n", d->mt.height);
	//
	if (!create_matrix(d))
		return (0);
	return (1);
}
