/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ku_objs_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:59:34 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/09 20:47:05 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

t_vec		ft_find_cy_t(t_minirt *rt, t_vec d, t_objs *obj, t_vec oc)
{
	t_vec	t;
	t_vec	h;
	t_vec	oc_h;
	double	dscr;
	double	a;

	h = mult_v(dot_v(d, obj->xyz_n), obj->xyz_n);
	h = sub_v(d, h);
	oc_h = mult_v(dot_v(oc, obj->xyz_n), obj->xyz_n);
	oc_h = sub_v(oc, oc_h);
	rt->ku.k1 = dot_v(h, h);
	rt->ku.k2 = 2 * dot_v(h, oc_h);
	rt->ku.k3 = dot_v(oc_h, oc_h) - pow(obj->cy_dm / 2, 2);
	dscr = pow(rt->ku.k2, 2) - 4 * rt->ku.k1 * rt->ku.k3;
	if (dscr < 0)
		return ((t_vec){INFINITY, INFINITY, 0});
	a = -rt->ku.k2 / (2 * rt->ku.k1);
	if (dscr == 0)
		return ((t_vec){a, a, 0});
	t.x = (-rt->ku.k2 + sqrt(dscr)) / (2 * rt->ku.k1);
	t.y = (-rt->ku.k2 - sqrt(dscr)) / (2 * rt->ku.k1);
	return (t);
}

double		ft_ku_cylinder(t_minirt *rt, t_objs *obj, t_vec o, t_vec d)
{
	t_vec	t;
	t_vec	p[2];
	double	h[2];
	double	res;
	t_vec	oc;

	res = INFINITY;
	obj->xyz_n = normalize_v(obj->xyz_n);
	oc = sub_v(obj->xyz, o);
	t = ft_find_cy_t(rt, d, obj, oc);
	if (t.x == INFINITY && t.y == INFINITY)
		return (INFINITY);
	p[0] = sum_v(o, mult_v(t.x, d));
	h[0] = dot_v(obj->xyz_n, sub_v(obj->xyz, p[0]));
	p[1] = sum_v(o, mult_v(t.y, d));
	h[1] = dot_v(obj->xyz_n, sub_v(obj->xyz, p[1]));
	if (-obj->cy_h / 2 <= h[0] && h[0] <= obj->cy_h / 2 && t.x > 0.000001)
		res = t.x;
	if (-obj->cy_h / 2 <= h[1] && h[1] <= obj->cy_h / 2 && t.y > 0.000001)
		res = t.y;
	return (res);
}

double		ft_ku_triangle(t_minirt *rt, t_objs *obj, t_vec v1, t_vec v2)
{
	t_vec	vec1;
	t_vec	vec2;
	t_vec	vec3;
	t_vec	vec4;
	t_vec	vec5;

	vec1 = sub_v(obj->xyz, obj->xyz2);
	vec2 = sub_v(obj->xyz, obj->xyz3);
	vec3 = cross_v(vec2, v2);
	rt->ku.k1 = dot_v(vec1, vec3);
	if (fabs(rt->ku.k1) < 0.01)
		return (INFINITY);
	vec4 = sub_v(obj->xyz, v1);
	rt->ku.k2 = dot_v(vec4, vec3) / rt->ku.k1;
	if (rt->ku.k2 < 0.0 || rt->ku.k2 > 1.0)
		return (INFINITY);
	vec5 = cross_v(vec1, vec4);
	rt->ku.k3 = dot_v(v2, vec5) / rt->ku.k1;
	if (rt->ku.k3 < 0.0 || rt->ku.k2 + rt->ku.k3 > 1.0)
		return (INFINITY);
	rt->ku.t1 = dot_v(vec2, vec5) / rt->ku.k1;
	return (rt->ku.t1);
}
