/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:08:38 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/05 17:42:04 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_matrix(t_data *d)
{
	t_list	*current;
	size_t		i;
	size_t	curr_len;

	d->mt.matrix = (char **)ft_calloc((d->mt.height + 1), sizeof(char *));
	if (!d->mt.matrix)
		return (0);
	current = d->lst->next;
	i = 0;
	while (i < d->mt.height)
	{
		d->mt.matrix[i] = (char *)ft_calloc(d->mt.maxlen + 1, sizeof(char));
		if (!d->mt.matrix[i])
		{
			free_split(&d->mt.matrix);
			return (0);
		}
		curr_len = ft_strlen((char *)current->content);
		if (curr_len < d->mt.maxlen)
		{
			ft_memcpy(d->mt.matrix[i], current->content, curr_len);
			ft_memset(d->mt.matrix[i] + curr_len, ' ', d->mt.maxlen - curr_len);
		}
		else
			ft_memcpy(d->mt.matrix[i], current->content, d->mt.maxlen);
		i++;
		current = current->next;
	}
	ft_lstclear(&d->lst, free);
	//
	i = 0;
	while (i < d->mt.height)
		printf("|%s|\n", d->mt.matrix[i++]);
	return (1);
}

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
	//
	printf("%s\t%p\n", tmpnew->content, tmpnew);
	//
	return (1);
}

int	process_map(t_data *d, int fd, int retval)
{
	//
	t_list	*head;
	//
	if (!(ft_isspace(*d->mp.line) || *d->mp.line == '1'))
		return (0);
	d->mp.line = tab_to_spaces(d->mp.line);
	d->mt.maxlen = ft_strlen(d->mp.line);
	ft_lstadd_back(&d->lst, ft_lstnew(ft_strdup(d->mp.line)));
	if (!d->lst->next)
		return (0);
	//
	head = d->lst->next;
	printf("%s\t%p\n", head->content, head);
	//
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
