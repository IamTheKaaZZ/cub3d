/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:50:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/04/19 15:51:02 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Inverts the given ARGB colour
*/

int	create_inverse_trgb(int colour)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (colour >> 24) & 255;
	r = (colour >> 16) & 255;
	r = 255 - r;
	g = (colour >> 8) & 255;
	g = 255 - g;
	b = colour & 255;
	b = 255 - b;
	return (t << 24 | r << 16 | g << 8 | b);
}
