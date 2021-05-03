/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:11:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/03 17:10:43 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Function to convert a string to a number, including negatives*
**only converts if first two chars are - and a digit or digits*
*/

int	ft_atoi(const char *numstr)
{
	int	i;
	int	res;
	int	sign;

	while (ft_isspace(*numstr))
		numstr++;
	i = 0;
	res = 0;
	sign = 1;
	if (*numstr == '-')
	{
		sign = -1;
		i++;
	}
	if (*numstr == '+')
		i++;
	while (*(numstr + i))
	{
		if (!ft_isdigit(numstr[i]))
			break ;
		res = res * 10 + numstr[i] - '0';
		i++;
	}
	return (res * sign);
}
