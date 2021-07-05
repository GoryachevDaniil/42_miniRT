/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:56:59 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 19:44:52 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

int			ft_key_comands(int keycode, t_minirt *rt)
{
	if (keycode == 53)
	{
		mlx_destroy_window(rt->mlx, rt->win);
		exit(0);
	}
	if (keycode == 48)
		ft_change_cam(rt);
	return (0);
}

int			ft_stop_it(void)
{
	exit(0);
}

void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
