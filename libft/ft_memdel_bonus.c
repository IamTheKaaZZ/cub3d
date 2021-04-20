/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 08:57:29 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/20 10:24:52 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_memdel(void **mem)
{
	if (mem != NULL)
	{
		free(*mem);
		*mem = NULL;
	}
}
