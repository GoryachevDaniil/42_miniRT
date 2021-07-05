/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_utils_part_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:59:30 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/10 13:40:45 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

t_vec		dev_v(t_vec vec, double s)
{
	vec.x = vec.x / s;
	vec.y = vec.y / s;
	vec.z = vec.z / s;
	return (vec);
}

t_vec		sub_v(t_vec one, t_vec two)
{
	t_vec	res;

	res.x = two.x - one.x;
	res.y = two.y - one.y;
	res.z = two.z - one.z;
	return (res);
}

t_vec		sum_v(t_vec one, t_vec two)
{
	t_vec	res;

	res.x = one.x + two.x;
	res.y = one.y + two.y;
	res.z = one.z + two.z;
	return (res);
}

t_vec		cross_v(t_vec one, t_vec two)
{
	t_vec	v;

	v.x = one.y * two.z - one.z * two.y;
	v.y = one.z * two.x - one.x * two.z;
	v.z = one.x * two.y - one.y * two.x;
	return (v);
}

t_vec		ft_mat_vec(t_vec r, t_vec u, t_vec n, t_vec d)
{
	t_vec	res;

	res.x = r.x * d.x + r.y * d.y + r.z * d.z;
	res.y = u.x * d.x + u.y * d.y + u.z * d.z;
	res.z = n.x * d.x + n.y * d.y + n.z * d.z;
	return (res);
}
