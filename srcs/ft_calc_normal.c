/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:48:57 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/12 04:39:39 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

void		ft_p_n_sphere(t_minirt *rt, t_objs *obj, double t_min)
{
	double	t;

	t = t_min;
	rt->p = sum_v(rt->m_cam->xyz, mult_v(t * 0.999, rt->d));
	rt->n = sub_v(obj->xyz, rt->p);
	rt->n = normalize_v(rt->n);
	rt->n_id = 1;
	rt->vn = obj->xyz;
	rt->vn_r = obj->sp_dm / 2;
}

void		ft_p_n_plane(t_minirt *rt, t_objs *obj, double t_min)
{
	double	t;

	t = t_min;
	rt->p = sum_v(rt->m_cam->xyz, mult_v(t * 0.99, rt->d));
	rt->n = normalize_v(obj->xyz_n);
	rt->n_id = 2;
}

void		ft_p_n_square(t_minirt *rt, t_objs *obj, double t_min)
{
	double t;

	t = t_min;
	rt->p = sum_v(rt->m_cam->xyz, mult_v(t * 0.99, rt->d));
	rt->n = normalize_v(obj->xyz_n);
	rt->n_id = 3;
}

void		ft_p_n_cylinder(t_minirt *rt, t_objs *obj, double t_min)
{
	t_vec	pc;
	double	t;

	t = t_min;
	rt->p = sum_v(rt->m_cam->xyz, mult_v(t * 0.99, rt->d));
	pc = sub_v(obj->xyz, rt->p);
	rt->n = sub_v(mult_v(dot_v(pc, obj->xyz_n), obj->xyz_n), pc);
	rt->n = normalize_v(rt->n);
	rt->n_id = 4;
	rt->vn = obj->xyz;
	rt->vn_r = obj->cy_dm / 2;
}

void		ft_p_n_triangle(t_minirt *rt, t_objs *obj, double t_min)
{
	double	t;

	t = t_min;
	rt->p = sum_v(rt->m_cam->xyz, mult_v(t * 0.99, rt->d));
	rt->n = cross_v(sub_v(obj->xyz, obj->xyz2), sub_v(obj->xyz, obj->xyz3));
	rt->n = normalize_v(rt->n);
	rt->n_id = 5;
}
