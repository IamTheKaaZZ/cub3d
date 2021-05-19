/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosters <bcosters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:57:34 by bcosters          #+#    #+#             */
/*   Updated: 2021/05/19 13:40:09 by bcosters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef union u_tobin
{
	uint32_t	nb;
	uint8_t		str[4];
}				t_tobin;

static void	itobin(t_uc *start, int nb)
{
	t_tobin	num;
	int		i;

	num.nb = nb;
	i = -1;
	while (++i < 4)
		start[i] = num.str[i];
}

static int	write_bmp_header(t_data *d, int fd)
{
	t_uc	header[54];

	ft_bzero(header, 54);
	header[0] = (t_uc)'B';
	header[1] = (t_uc)'M';
	itobin(header + 2, 54 + d->m.win_h * d->m.win_w * 3);
	header[10] = (t_uc)54;
	header[14] = (t_uc)40;
	itobin(header + 18, d->m.win_w);
	itobin(header + 22, d->m.win_h);
	header[27] = (t_uc)1;
	header[28] = (t_uc)24;
	return (write(fd, header, 54));
}

void	take_screenshot(t_data *d)
{
	int		fd;
	int		x;
	int		y;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0 || write_bmp_header(d, fd) < 0)
		flush_data(d, BMP_ERR, TRUE);
	render_next_frame(d);
	y = d->m.win_h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < d->m.win_w)
		{
			write(fd, &d->m.img.addr[y * (d->m.win_w) + x], 3);
			x++;
		}
		y--;
	}
	close(fd);
	close_window(d);
}