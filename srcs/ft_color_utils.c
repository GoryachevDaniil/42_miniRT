/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:02:19 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/12 05:03:21 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

t_color		ft_c_k(t_color clr, double i)
{
	clr.r = clr.r * i;
	clr.g = clr.g * i;
	clr.b = clr.b * i;
	ft_check_rgb_2(&clr.r, &clr.g, &clr.b);
	return (clr);
}

t_color		ft_c_c(t_color c1, t_color c2)
{
	t_color	res_color;

	res_color.r = c1.r + c2.r;
	res_color.g = c1.g + c2.g;
	res_color.b = c1.b + c2.b;
	ft_check_rgb_2(&res_color.r, &res_color.g, &res_color.b);
	return (res_color);
}

t_color		ft_c_c_k(t_color c1, t_color c2, double kf)
{
	t_color	c_res;

	c_res.r = c1.r + c2.r * kf;
	c_res.g = c1.g + c2.g * kf;
	c_res.b = c1.b + c2.b * kf;
	ft_check_rgb_2(&c_res.r, &c_res.g, &c_res.b);
	return (c_res);
}

t_color		ft_c_k_c_k(t_color c1, double k1, t_color c2, double k2)
{
	t_color	c_res;

	c_res.r = c1.r * k1 + c2.r * k2;
	c_res.g = c1.g * k1 + c2.g * k2;
	c_res.b = c1.b * k1 + c2.b * k2;
	ft_check_rgb_2(&c_res.r, &c_res.g, &c_res.b);
	return (c_res);
}

int			ft_create_trgb(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
