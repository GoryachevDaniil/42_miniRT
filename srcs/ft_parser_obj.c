/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:29:10 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 21:02:17 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

void		ft_parse_tr(char *line, t_minirt *rt)
{
	t_objs	*tmp;

	if (*line == '\0')
		return ;
	if (!(tmp = malloc(sizeof(t_objs))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 5)
		ft_err_ex_minirt(rt, "Invalid number of arguments of triangle.");
	tmp->id = 5;
	if (ft_check_split(rt->split_xyz = ft_split(rt, rt->split[1], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of triangle.");
	tmp->xyz = ft_make_vec(rt->split_xyz, rt);
	if (ft_check_split(rt->split_xyz_2 = ft_split(rt, rt->split[2], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of triangle.");
	tmp->xyz2 = ft_make_vec(rt->split_xyz_2, rt);
	if (ft_check_split(rt->split_xyz_3 = ft_split(rt, rt->split[3], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of triangle.");
	tmp->xyz3 = ft_make_vec(rt->split_xyz_3, rt);
	if (ft_check_split(rt->split_rgb = ft_split(rt, rt->split[4], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid colors of triangle.");
	ft_check_tr(rt, tmp);
	tmp->color = ft_check_rgb(rt, ft_make_color(rt->split_rgb, rt));
	ft_lstadd_back(&rt->objs, ft_lstnew(tmp));
	ft_free_all_split(rt);
}

void		ft_parse_cy(char *line, t_minirt *rt)
{
	t_objs	*tmp;

	if (*line == '\0')
		return ;
	if (!(tmp = malloc(sizeof(t_objs))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 6)
		ft_err_ex_minirt(rt, "Invalid number of arguments of cylinder.");
	tmp->id = 4;
	if (ft_check_split(rt->split_xyz = ft_split(rt, rt->split[1], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of cylinder.");
	tmp->xyz = ft_make_vec(rt->split_xyz, rt);
	if (ft_check_split(rt->split_xyz_n = ft_split(rt, rt->split[2], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid normalized vector of cylinder.");
	tmp->xyz_n = ft_make_vec(rt->split_xyz_n, rt);
	ft_check_normla_xyz(tmp->xyz_n.x, tmp->xyz_n.y, tmp->xyz_n.z, rt);
	tmp->cy_dm = ft_atof_rt(rt->split[3], rt);
	tmp->cy_h = ft_atof_rt(rt->split[4], rt);
	if (tmp->cy_dm < 0 || tmp->cy_h < 0)
		ft_err_ex_minirt(rt, "Invalid diametr or hight of cylinder.");
	if (ft_check_split(rt->split_rgb = ft_split(rt, rt->split[5], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid colors of cylinder.");
	tmp->color = ft_check_rgb(rt, ft_make_color(rt->split_rgb, rt));
	ft_lstadd_back(&rt->objs, ft_lstnew(tmp));
	ft_free_all_split(rt);
}

void		ft_parse_sq(char *line, t_minirt *rt)
{
	t_objs	*tmp;

	if (*line == '\0')
		return ;
	if (!(tmp = malloc(sizeof(t_objs))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 5)
		ft_err_ex_minirt(rt, "Invalid number of arguments of square.");
	tmp->id = 3;
	if (ft_check_split(rt->split_xyz = ft_split(rt, rt->split[1], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of square.");
	tmp->xyz = ft_make_vec(rt->split_xyz, rt);
	if (ft_check_split(rt->split_xyz_2 = ft_split(rt, rt->split[2], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid normalized vector of square.");
	tmp->xyz_n = ft_make_vec(rt->split_xyz_2, rt);
	if (tmp->xyz_n.x == 1.0 && tmp->xyz_n.y == 1.0 && tmp->xyz_n.z == 1.0)
		tmp->xyz_n.z = 0;
	ft_check_normla_xyz(tmp->xyz_n.x, tmp->xyz_n.y, tmp->xyz_n.z, rt);
	tmp->sq_dl = ft_atof_rt(rt->split[3], rt);
	tmp->sq_dl < 0 ? ft_err_ex_minirt(rt, "Invalid argumet of square.") : 0;
	if (ft_check_split(rt->split_rgb = ft_split(rt, rt->split[4], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid colors of square.");
	tmp->color = ft_check_rgb(rt, ft_make_color(rt->split_rgb, rt));
	ft_lstadd_back(&rt->objs, ft_lstnew(tmp));
	ft_free_all_split(rt);
}

void		ft_parse_pl(char *line, t_minirt *rt)
{
	t_objs	*tmp;

	if (*line == '\0')
		return ;
	if (!(tmp = malloc(sizeof(t_objs))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 4)
		ft_err_ex_minirt(rt, "Invalid number of arguments of plane.");
	tmp->id = 2;
	if (ft_check_split(rt->split_xyz = ft_split(rt, rt->split[1], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of plane.");
	tmp->xyz = ft_make_vec(rt->split_xyz, rt);
	if (ft_check_split(rt->split_xyz_2 = ft_split(rt, rt->split[2], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid normalized orientation vector of plane.");
	tmp->xyz_n = ft_make_vec(rt->split_xyz_2, rt);
	ft_check_normla_xyz(tmp->xyz_n.x, tmp->xyz_n.y, tmp->xyz_n.z, rt);
	if (ft_check_split(rt->split_rgb = ft_split(rt, rt->split[3], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid colors of plane.");
	tmp->color = ft_check_rgb(rt, ft_make_color(rt->split_rgb, rt));
	ft_lstadd_back(&rt->objs, ft_lstnew(tmp));
	ft_free_all_split(rt);
}

void		ft_parse_sp(char *line, t_minirt *rt)
{
	t_objs	*tmp;

	if (*line == '\0')
		return ;
	if (!(tmp = malloc(sizeof(t_objs))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	if (ft_check_split(rt->split = ft_split_set(&line[rt->i], rt->tabu)) != 4)
		ft_err_ex_minirt(rt, "Invalid number of arguments of sphere.");
	tmp->id = 1;
	if (ft_check_split(rt->split_xyz = ft_split(rt, rt->split[1], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid coordinates of sphere.");
	tmp->xyz = ft_make_vec(rt->split_xyz, rt);
	tmp->sp_dm = ft_atof_rt(rt->split[2], rt);
	if (tmp->sp_dm < 0)
		ft_err_ex_minirt(rt, "Invalid argumet of sphere.");
	if (ft_check_split(rt->split_rgb = ft_split(rt, rt->split[3], ',')) != 3)
		ft_err_ex_minirt(rt, "Invalid colors of sphere.");
	tmp->color = ft_check_rgb(rt, ft_make_color(rt->split_rgb, rt));
	ft_lstadd_back(&rt->objs, ft_lstnew(tmp));
	ft_free_all_split(rt);
}
