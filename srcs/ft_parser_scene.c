/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:33:45 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 20:17:48 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

void		ft_check_tr(t_minirt *rt, t_objs *tmp)
{
	if (ft_vec_cmp(tmp->xyz, tmp->xyz2) || ft_vec_cmp(tmp->xyz, tmp->xyz3)
		|| ft_vec_cmp(tmp->xyz2, tmp->xyz3))
		ft_err_ex_minirt(rt, "Invalid coordinates of triangle.");
}

void		ft_parse_light(char *line, t_minirt *rt)
{
	t_light	*tmp;

	if (*line == '\0')
		return ;
	if (!(tmp = malloc(sizeof(t_light))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 4)
		ft_err_ex_minirt(rt, "Invalid number of arguments of light.");
	tmp->id = 7;
	if (ft_check_split(rt->split_xyz = ft_split(rt, rt->split[1], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of light.");
	tmp->xyz = ft_make_vec(rt->split_xyz, rt);
	tmp->ratio = ft_atof_rt(rt->split[2], rt);
	if (tmp->ratio > 1 || tmp->ratio < -1)
		ft_err_ex_minirt(rt, "Invalid ratio of light.");
	if (ft_check_split(rt->split_rgb = ft_split(rt, rt->split[3], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid colors of light.");
	tmp->color = ft_check_rgb(rt, ft_make_color(rt->split_rgb, rt));
	ft_lstadd_back(&rt->light, ft_lstnew(tmp));
	ft_free_all_split(rt);
}

void		ft_parse_cam(char *line, t_minirt *rt)
{
	t_cam	*tmp;

	if (*line == '\0')
		return ;
	if (!(tmp = malloc(sizeof(t_cam))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 4)
		ft_err_ex_minirt(rt, "Invalid number of arguments of camera.");
	tmp->id = 6;
	if (ft_check_split(rt->split_xyz = ft_split(rt, rt->split[1], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of camera.");
	tmp->xyz = ft_make_vec(rt->split_xyz, rt);
	if (ft_check_split(rt->split_xyz_n = ft_split(rt, rt->split[2], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid normalized vector of camera.");
	tmp->xyz_n.x = ft_atof_rt(rt->split_xyz_n[0], rt) * -1;
	tmp->xyz_n.y = ft_atof_rt(rt->split_xyz_n[1], rt) * -1;
	tmp->xyz_n.z = ft_atof_rt(rt->split_xyz_n[2], rt);
	ft_check_normla_xyz(tmp->xyz_n.x, tmp->xyz_n.y, tmp->xyz_n.z, rt);
	tmp->fov = ft_atoi_rt(rt->split[3], rt);
	if (tmp->fov <= 0 || tmp->fov > 180)
		ft_err_ex_minirt(rt, "Invalid camera FOV.");
	rt->cam_count += 1;
	ft_lstadd_back(&rt->cam, ft_lstnew(tmp));
	ft_free_all_split(rt);
}

void		ft_parse_amb(char *line, t_minirt *rt)
{
	if (*line == '\0')
		return ;
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 3)
		ft_err_ex_minirt(rt, "Invalid number of arguments of ambient.");
	rt->amb.range = ft_atof_rt(rt->split[1], rt);
	if (rt->amb.range > 1 || rt->amb.range < 0)
		ft_err_ex_minirt(rt, "Invalid ambient range.");
	if (ft_check_split(rt->split_rgb = ft_split(rt, rt->split[2], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid ambient color.");
	rt->amb.color = ft_check_rgb(rt, ft_make_color(rt->split_rgb, rt));
	rt->amb_pars += 1;
	ft_free_all_split(rt);
}

void		ft_parse_res(char *line, t_minirt *rt)
{
	int		x;
	int		y;

	if (*line == '\0')
		return ;
	rt->split = ft_split_set(&line[rt->i], rt->tabu);
	if (ft_check_split(rt->split) != 3)
		ft_err_ex_minirt(rt, "Invalid number of arguments of permission.");
	if (ft_strlen(rt->split[1]) <= 10 || ft_strlen(rt->split[2]) <= 10)
	{
		rt->res.x = ft_atoi_rt(rt->split[1], rt);
		rt->res.y = ft_atoi_rt(rt->split[2], rt);
		mlx_get_screen_size(rt->mlx, &x, &y);
		rt->res.x > x ? rt->res.x = x : 0;
		rt->res.y > y ? rt->res.y = y : 0;
	}
	else
		mlx_get_screen_size(rt->mlx, &rt->res.x, &rt->res.y);
	if (rt->res.x < 1 || rt->res.y < 1)
		ft_err_ex_minirt(rt, "Invalid permission.");
	rt->res_pars += 1;
	ft_free_all_split(rt);
}
