/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:25:05 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/20 18:07:06 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

void		ft_inter_search(t_minirt *rt, double tm, t_vec v1, t_vec v2)
{
	t_objs	*ptr;
	t_list	*tmp;
	double	t;

	tmp = rt->objs;
	rt->m_obj = NULL;
	rt->t_min = INFINITY;
	while (tmp)
	{
		ptr = tmp->content;
		ptr->id == 1 ? t = ft_ku_sphere(rt, ptr, v1, v2) : 0;
		ptr->id == 2 ? t = ft_ku_plane(rt, ptr, v1, v2) : 0;
		ptr->id == 3 ? t = ft_ku_square(rt, ptr, v1, v2) : 0;
		ptr->id == 4 ? t = ft_ku_cylinder(rt, ptr, v1, v2) : 0;
		ptr->id == 5 ? t = ft_ku_triangle(rt, ptr, v1, v2) : 0;
		if (t > 0.00001 && t < rt->t_min * 0.9999 && t < tm)
		{
			rt->t_min = t;
			rt->m_obj = ptr;
		}
		tmp = tmp->next;
	}
}

int			ft_traceray(t_minirt *rt, t_vec v1, t_vec v2)
{
	rt->t_min = INFINITY;
	ft_inter_search(rt, INFINITY, v1, v2);
	if (rt->m_obj == NULL)
		return (ft_create_trgb(ft_c_k(rt->amb.color, rt->amb.range)));
	rt->m_obj->id == 1 ? ft_p_n_sphere(rt, rt->m_obj, rt->t_min) : 0;
	rt->m_obj->id == 2 ? ft_p_n_plane(rt, rt->m_obj, rt->t_min) : 0;
	rt->m_obj->id == 3 ? ft_p_n_square(rt, rt->m_obj, rt->t_min) : 0;
	rt->m_obj->id == 4 ? ft_p_n_cylinder(rt, rt->m_obj, rt->t_min) : 0;
	rt->m_obj->id == 5 ? ft_p_n_triangle(rt, rt->m_obj, rt->t_min) : 0;
	return (ft_create_trgb(ft_light(rt, rt->n, rt->p, rt->m_obj)));
}

void		ft_render(t_minirt *rt)
{
	rt->x = -rt->res.x / 2;
	rt->y = -rt->res.y / 2;
	rt->image.img = mlx_new_image(rt->mlx, rt->res.x, rt->res.y);
	rt->image.addr = mlx_get_data_addr(rt->image.img, &rt->image.bpp,
			&rt->image.line_length, &rt->image.endian);
	while (++rt->y < rt->res.y / 2 - 1)
	{
		rt->x = -rt->res.x / 2;
		while (++rt->x < rt->res.x / 2 - 1)
		{
			rt->d = ft_cam_direction(rt, rt->x, rt->y);
			rt->local_color = ft_traceray(rt, rt->m_cam->xyz, rt->d);
			my_mlx_pixel_put(&rt->image, rt->res.x / 2 + rt->x,
				rt->res.y / 2 - rt->y, rt->local_color);
		}
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->image.img, 0, 0);
}

void		ft_raytrace_start(t_minirt *rt)
{
	ft_choose_cam(rt);
	rt->mlx = mlx_init();
	rt->win = mlx_new_window(rt->mlx, rt->res.x, rt->res.y, "miniRT");
	ft_render(rt);
	if (rt->bmp == 1)
		ft_save_bmp_image(rt);
	mlx_hook(rt->win, 2, 1L << 0, ft_key_comands, rt);
	mlx_hook(rt->win, 17, 1L << 0, ft_stop_it, rt);
	mlx_loop(rt->mlx);
}
