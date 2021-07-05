/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_utils_part_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:03:30 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/10 13:44:43 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

int			ft_ugl(t_vec l, t_vec n)
{
	double	mdla;
	double	mdlb;
	double	mdlab;
	double	cos;
	double	ugl;

	mdla = sqrt(l.x * l.x + l.y * l.y + l.z * l.z);
	mdlb = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
	mdlab = mdla * mdlb;
	cos = (l.x * n.x + l.y * n.y + l.z * n.z) / mdlab;
	ugl = acos(cos) * 180 / M_PI;
	if (ugl > 90)
		return (1);
	return (0);
}

double		dot_v(t_vec one, t_vec two)
{
	return (one.x * two.x + one.y * two.y + one.z * two.z);
}

double		len_v(t_vec vec)
{
	return (sqrt(dot_v(vec, vec)));
}

t_vec		normalize_v(t_vec v)
{
	t_vec	res;
	double	len;

	len = len_v(v);
	res.x = v.x / len;
	res.y = v.y / len;
	res.z = v.z / len;
	return (res);
}

t_vec		mult_v(double k, t_vec vec)
{
	vec.x = k * vec.x;
	vec.y = k * vec.y;
	vec.z = k * vec.z;
	return (vec);
}
