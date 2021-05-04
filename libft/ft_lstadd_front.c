/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:28:17 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/04 15:06:23 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Add the new list elem to the front of the list
**	AKA next becomes the first elem of the list
**	THEN the new elem is pushed in front of the first elem of the list
**	SO: the new elem is now the first in the list
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
