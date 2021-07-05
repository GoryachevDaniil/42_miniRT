/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 22:26:16 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 20:39:32 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

double		ft_atof_rt(char *str, t_minirt *rt)
{
	double	r1;
	double	r2;
	int		l;
	int		k;
	int		i;

	i = 0;
	k = 1;
	r1 = (double)ft_atoi_rt(str, rt);
	str[i] == '-' && r1 == 0 ? k = -1 : 0;
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	if (*str == '.')
		ft_err_ex_minirt(rt, "Invalid arguments.");
	r2 = (double)ft_atoi_rt(str, rt);
	l = ft_strlen(str);
	while (l--)
		r2 /= 10;
	return ((r1 + r2) * k);
}
