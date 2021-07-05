/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:58:04 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/10 13:30:35 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

double		ft_bliki(t_minirt *rt, t_light *p_l, t_vec n, t_vec p)
{
	double	i;

	rt->d2 = mult_v(-1, rt->d);
	i = p_l->ratio * pow(dot_v(sub_v(sub_v(p, p_l->xyz),
		mult_v(2, mult_v(dot_v(n, sub_v(p, p_l->xyz)),
		n))), rt->d2) / (len_v(sub_v(sub_v(p, p_l->xyz),
		mult_v(2, mult_v(dot_v(n, sub_v(p, p_l->xyz)),
		n)))) * len_v(rt->d2)), 300);
	return (i);
}

double		ft_if_bliki(t_minirt *rt, t_light *p_l, t_vec n, t_vec p)
{
	return (dot_v(sub_v(sub_v(p, p_l->xyz), mult_v(2,
			mult_v(dot_v(n, sub_v(p, p_l->xyz)), n))), mult_v(-1, rt->d)));
}

double		ft_svet(t_light *p_l, t_vec n, t_vec p)
{
	double	i;

	i = p_l->ratio * dot_v(n, sub_v(p, p_l->xyz))
		/ (len_v(n) * len_v(sub_v(p, p_l->xyz)));
	return (i);
}

void		ft_resault_light(t_minirt *rt, t_light *p_l, t_vec n, t_vec p)
{
	t_vec	l;

	l = sub_v(p, p_l->xyz);
	if ((rt->n_id == 2 || rt->n_id == 3 || rt->n_id == 5) && ft_ugl(l, n))
		n = mult_v(-1, n);
	if ((rt->n_id == 1 || rt->n_id == 4) && dot_v(n, sub_v(p, p_l->xyz)) < 0)
		if (ft_cam_inside_obj(rt))
			n = mult_v(-1, n);
	dot_v(n, sub_v(p, p_l->xyz)) > 0 ? rt->intens = ft_svet(p_l, n, p) : 0;
	ft_if_bliki(rt, p_l, n, p) > 0 ? rt->intens += ft_bliki(rt, p_l, n, p) : 0;
	rt->res_color = ft_c_c_k(rt->res_color, p_l->color, rt->intens);
}

t_color		ft_light(t_minirt *rt, t_vec n, t_vec p, t_objs *main)
{
	t_list	*tmp_l;
	t_light	*p_l;

	tmp_l = rt->light;
	rt->res_color = ft_c_k_c_k(main->color, rt->amb.range,
		rt->amb.color, rt->amb.range);
	while (tmp_l)
	{
		rt->intens = 0;
		p_l = tmp_l->content;
		ft_inter_search(rt, 0.9999, p, sub_v(p, p_l->xyz));
		if (rt->m_obj != NULL)
		{
			tmp_l = tmp_l->next;
			continue ;
		}
		ft_resault_light(rt, p_l, n, p);
		tmp_l = tmp_l->next;
	}
	return (rt->res_color);
}
