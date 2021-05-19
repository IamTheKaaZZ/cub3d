/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:35:55 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/19 13:17:24 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_handling(int errnum)
{
	ft_putstr_fd("\nError:\t", 2);
	if (errnum == NOT_ENOUGH_ARGS || errnum == TOO_MANY_ARGS
		|| errnum == INVALID_FLAG || errnum == NO_CUB_FILE_TYPE)
	{
		if (errnum == NOT_ENOUGH_ARGS)
			ft_putendl_fd("Not enough arguments.\n", 2);
		else if (errnum == TOO_MANY_ARGS)
			ft_putendl_fd("Too many arguments.\n", 2);
		else if (errnum == NO_CUB_FILE_TYPE)
			ft_putendl_fd("Wrong file type for map.\n", 2);
		else
			ft_putendl_fd("Invalid flag.\n", 2);
		ft_putstr_fd("USAGE: map file in *.cub format", 2);
		ft_putendl_fd(" OR *.cub + --save to save the image.\n", 2);
	}
	else if (errnum == OPEN_ERR)
		ft_putendl_fd("Unable to open map file.\n", 2);
	else if (errnum == READ_ERR)
		ft_putendl_fd("Unable to read the map file correctly.\n", 2);
	else if (errnum == OVERWRITE_ERR)
		ft_putendl_fd("Multiple definitions for the same elements.\n", 2);
	else if (errnum == RES_ERR)
		ft_putendl_fd("Unable to read the resolution correctly.\n", 2);
	else if (errnum == INVALID_PATH_CHR)
		ft_putendl_fd("Invalid characters in texture path.\n", 2);
	else if (errnum == RGB_ERR)
		ft_putendl_fd("Unable to read the RGB colour correctly.\n", 2);
	else if (errnum == DATA_ERR)
		ft_putendl_fd("Something went wrong during data parsing.\n", 2);
	else if (errnum == MAP_ERR)
		ft_putendl_fd("The provided map is invalid.\n", 2);
	else if (errnum == BMP_ERR)
		ft_putendl_fd("Could not create the screenshot.\n", 2);
	exit(EXIT_FAILURE);
}
