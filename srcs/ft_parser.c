/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:20:06 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/20 18:03:29 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

int			ft_vec_cmp(t_vec v1, t_vec v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (1);
	return (0);
}

t_vec		ft_make_vec(char **arr, t_minirt *rt)
{
	t_vec	res;

	res.x = ft_atof_rt(arr[0], rt);
	res.y = ft_atof_rt(arr[1], rt);
	res.z = ft_atof_rt(arr[2], rt);
	return (res);
}

t_color		ft_make_color(char **arr, t_minirt *rt)
{
	t_color res;

	res.r = ft_atoi_rt(arr[0], rt);
	res.g = ft_atoi_rt(arr[1], rt);
	res.b = ft_atoi_rt(arr[2], rt);
	return (res);
}

void		ft_parse_line(char *line, t_minirt *rt)
{
	if (line[rt->i] == '#')
		return ;
	else if (line[rt->i] == 'R')
		ft_parse_res(line, rt);
	else if (line[rt->i] == 'A')
		ft_parse_amb(line, rt);
	else if (line[rt->i] == 'c' && line[rt->i + 1] != 'y')
		ft_parse_cam(line, rt);
	else if (line[rt->i] == 'l')
		ft_parse_light(line, rt);
	else if (line[rt->i] == 'p' && line[rt->i + 1] == 'l')
		ft_parse_pl(line, rt);
	else if (line[rt->i] == 's' && line[rt->i + 1] == 'p')
		ft_parse_sp(line, rt);
	else if (line[rt->i] == 's' && line[rt->i + 1] == 'q')
		ft_parse_sq(line, rt);
	else if (line[rt->i] == 'c' && line[rt->i + 1] == 'y')
		ft_parse_cy(line, rt);
	else if (line[rt->i] == 't' && line[rt->i + 1] == 'r')
		ft_parse_tr(line, rt);
	else if (line[rt->i == '\0'])
		return ;
}

void		ft_parser_rt(char *line, t_minirt *rt)
{
	rt->i = 0;
	ft_parse_line(line, rt);
}
