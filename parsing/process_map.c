/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:08:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/21 11:32:29 by bcosters         ###   ########.fr       */
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

static int	add_to_list(t_data *d, t_list *game_map)
{
	t_list	*tmpnew;

	d->sc.gnl = tab_to_spaces(d->sc.gnl);
	if ((int)ft_strlen(d->sc.gnl) > d->mp.max_x)
		d->mp.max_x = ft_strlen(d->sc.gnl);
	tmpnew = ft_lstnew(ft_strdup(d->sc.gnl));
	if (!tmpnew)
		return (0);
	ft_lstadd_back(&game_map, tmpnew);
	ft_strdel(&d->sc.gnl);
	return (1);
}

int	process_map(t_data *d, int fd, int retval)
{
	t_list	*game_map;

	game_map = ft_lstnew(NULL);
	if (!(ft_isspace(*d->sc.gnl) || *d->sc.gnl == '1') || !game_map)
		return (0);
	d->sc.gnl = tab_to_spaces(d->sc.gnl);
	d->mp.max_x = ft_strlen(d->sc.gnl);
	ft_lstadd_back(&game_map, ft_lstnew(ft_strdup(d->sc.gnl)));
	if (!game_map->next)
		return (0);
	ft_strdel(&d->sc.gnl);
	while (retval)
	{
		retval = get_next_line(fd, &d->sc.gnl);
		if (!(ft_isspace(*d->sc.gnl) || d->sc.gnl[0] == '1'))
			return (0);
		if (!add_to_list(d, game_map))
			return (0);
	}
	d->mp.max_y = ft_lstsize(game_map) - 1;
	if (!create_matrix(d, game_map))
		return (0);
	return (1);
}
