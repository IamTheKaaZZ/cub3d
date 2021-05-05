/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:19:31 by bcosters          #+#    #+#             */
/*   Updated: 2021/02/15 16:33:26 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Checks if char c is part of 8 bit ASCII*
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}