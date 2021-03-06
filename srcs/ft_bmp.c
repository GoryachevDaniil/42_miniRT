/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:55:37 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/09 19:49:27 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

static void	transfer(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static void	bmp_header(t_minirt *rt, int file_size, int fd)
{
	unsigned char btr[54];

	ft_bzero(btr, 54);
	btr[0] = (unsigned char)('B');
	btr[1] = (unsigned char)('M');
	transfer(file_size, btr + 2);
	btr[10] = (unsigned char)(54);
	btr[14] = (unsigned char)(40);
	transfer(rt->res.x, btr + 18);
	transfer(rt->res.y, btr + 22);
	btr[26] = (unsigned char)(1);
	btr[28] = (unsigned char)(24);
	write(fd, btr, 54);
}

static void	get_pixel(t_minirt *rt, int fd)
{
	int		i;
	int		j;
	int		color;

	i = rt->res.y - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < rt->res.x)
		{
			color = *(int*)(rt->image.addr +
			(i * rt->image.line_length + j * (rt->image.bpp / 8)));
			write(fd, &color, 3);
		}
		i--;
	}
}

void		ft_save_bmp_image(t_minirt *rt)
{
	int		fd;
	int		size;

	while (rt->res.x % 4 != 0)
		rt->res.x--;
	size = 54 + (4 * rt->res.y * rt->res.x);
	if (!(fd = open("screen.bmp", O_WRONLY | O_CREAT |
			O_TRUNC | O_APPEND, 0666)))
		ft_err_ex_minirt(rt, "Fail to bmp");
	bmp_header(rt, size, fd);
	get_pixel(rt, fd);
	close(fd);
	exit(0);
}
