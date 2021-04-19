/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:35:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 17:15:48 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_handling(int errnum)
{
	ft_putendl_fd("Error:\n", 2);
	if (errnum == NOT_ENOUGH_ARGS || errnum == TOO_MANY_ARGS
		|| errnum == INVALID_FLAG)
	{
		if (errnum == NOT_ENOUGH_ARGS)
			ft_putendl_fd("Not enough arguments.\n", 2);
		else if (errnum == TOO_MANY_ARGS)
			ft_putendl_fd("Too many arguments.\n", 2);
		else
			ft_putendl_fd("Invalid flag.\n", 2);
		ft_putstr_fd("USAGE: map file in *.cub format", 2);
		ft_putendl_fd("OR *.cub + --save to save the image.\n", 2);
	}
}
