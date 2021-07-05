/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:56:06 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/09 20:04:40 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

int			ft_cam_inside_obj(t_minirt *rt)
{
	double	x;
	double	y;
	double	z;
	double	t;

	x = rt->m_cam->xyz.x - rt->vn.x;
	y = rt->m_cam->xyz.y - rt->vn.y;
	z = rt->m_cam->xyz.z - rt->vn.z;
	t = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	if (t < rt->vn_r)
		return (1);
	return (0);
}

t_vec		ft_canvas_to_viewport(t_minirt *rt, double x, double y, double z)
{
	t_vec v;

	v.x = x / rt->res.y * 2 * tan(rt->m_cam->fov / 2 * M_PI / 180);
	v.y = y / rt->res.y * 2 * tan(rt->m_cam->fov / 2 * M_PI / 180);
	v.z = z;
	return (v);
}

t_vec		ft_cam_direction(t_minirt *rt, double x, double y)
{
	t_vec	v_right;
	t_vec	v_up;
	t_vec	v_vp;
	t_vec	direction;
	t_vec	norm;

	norm = normalize_v(rt->m_cam->xyz_n);
	v_vp = ft_canvas_to_viewport(rt, x, y, 1);
	v_right = cross_v((t_vec){0.0, 1.0, 0.0}, norm);
	v_up = cross_v(norm, v_right);
	direction = ft_mat_vec(v_right, v_up, norm, v_vp);
	return (direction);
}

void		ft_choose_cam(t_minirt *rt)
{
	rt->tmp = rt->cam;
	rt->m_cam = rt->cam->content;
}

void		ft_change_cam(t_minirt *rt)
{
	mlx_clear_window(rt->mlx, rt->win);
	if (rt->cam->next == NULL)
		rt->cam = rt->tmp;
	else
		rt->cam = rt->cam->next;
	rt->m_cam = rt->cam->content;
	ft_render(rt);
}
