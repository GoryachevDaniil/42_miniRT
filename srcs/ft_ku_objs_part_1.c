/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ku_objs_part_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:15:07 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/12 04:38:25 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

double		ft_ku_sphere(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2)
{
	t_vec	oc;

	oc = sub_v(obj->xyz, v1);
	rt->sp_r = obj->sp_dm / 2;
	rt->ku.k1 = dot_v(v2, v2);
	rt->ku.k2 = 2 * dot_v(oc, v2);
	rt->ku.k3 = dot_v(oc, oc) - (rt->sp_r * rt->sp_r);
	rt->ku.disc = rt->ku.k2 * rt->ku.k2 - 4 * rt->ku.k1 * rt->ku.k3;
	if (rt->ku.disc < 0)
		return (INFINITY);
	rt->ku.t1 = (-rt->ku.k2 + sqrt(rt->ku.disc)) / (2 * rt->ku.k1);
	rt->ku.t2 = (-rt->ku.k2 - sqrt(rt->ku.disc)) / (2 * rt->ku.k1);
	if ((rt->ku.t1 > 0 && rt->ku.t2 > 0) &&
			(rt->ku.t1 > rt->ku.t2 || rt->ku.t1 == rt->ku.t2))
		return (rt->ku.t2);
	else if ((rt->ku.t1 > 0 && rt->ku.t2 > 0) && rt->ku.t1 < rt->ku.t2)
		return (rt->ku.t1);
	else if ((rt->ku.t1 > 0 && rt->ku.t2 < 0))
		return (rt->ku.t1);
	else if ((rt->ku.t1 < 0 && rt->ku.t2 > 0))
		return (rt->ku.t2);
	else
		return (INFINITY);
}

double		ft_ku_plane(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2)
{
	double	t;

	obj->xyz_n = normalize_v(obj->xyz_n);
	rt->ku.k1 = -dot_v(obj->xyz_n, obj->xyz);
	rt->ku.k2 = dot_v(obj->xyz_n, v2);
	rt->ku.k3 = dot_v(obj->xyz_n, v1) + rt->ku.k1;
	if (rt->ku.k2 == 0)
		return (INFINITY);
	if (fabs(rt->ku.k2) < 0.0000001)
		return (INFINITY);
	t = -rt->ku.k3 / rt->ku.k2;
	return (t);
}

double		ft_ku_square(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2)
{
	t_vec	d;

	obj->xyz_n = normalize_v(obj->xyz_n);
	rt->ku.k1 = dot_v(sub_v(obj->xyz, v1), obj->xyz_n);
	rt->ku.k2 = dot_v(v2, obj->xyz_n);
	if (rt->ku.k2 == 0 || (rt->ku.k1 < 0 && rt->ku.k2 < 0)
		|| (rt->ku.k1 > 0 && rt->ku.k2 > 0))
		return (INFINITY);
	rt->ku.t1 = rt->ku.k1 / rt->ku.k2 * -1.0;
	d = sub_v(obj->xyz, sum_v(mult_v(rt->ku.t1, v2), v1));
	rt->ku.t2 = obj->sq_dl / 2;
	if (fabs(d.x) > rt->ku.t2 || fabs(d.y) > rt->ku.t2 || fabs(d.z) > rt->ku.t2)
		return (INFINITY);
	if (rt->ku.t1 > 0)
		return (rt->ku.t1);
	return (INFINITY);
}
