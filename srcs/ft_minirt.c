/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:06:11 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/20 18:27:44 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

void			ft_err_ex_minirt(t_minirt *rt, char *str)
{
	ft_putstr(str);
	ft_free_all_split(rt);
	exit(0);
}

void			ft_make_rt_file(t_list **list, int size, t_minirt *rt)
{
	char		**file;
	int			j;
	int			m;
	t_list		*tmp;

	tmp = *list;
	j = -1;
	if (!(file = calloc(size + 1, sizeof(char *))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	while (tmp)
	{
		file[++j] = tmp->content;
		free(tmp);
		tmp = tmp->next;
	}
	j = -1;
	m = -1;
	while (file[++m])
		ft_parser_rt(file[++j], rt);
	ft_free_arr(file);
}

void			ft_open_rt_file(char *file, t_minirt *rt)
{
	int			fd;
	char		*line;
	t_list		*list;
	int			def;

	list = NULL;
	fd = open(file, O_RDONLY);
	while ((def = get_next_line(fd, &line)) > 0)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
	}
	if (def == -1)
		ft_err_ex_minirt(rt, "GNL ERROR.");
	ft_lstadd_back(&list, ft_lstnew(line));
	ft_make_rt_file(&list, ft_lstsize(list), rt);
}

void			ft_inicializate_t_minirt(t_minirt *rt)
{
	rt->i = 0;
	rt->k = 0;
	rt->cam_count = 0;
	rt->amb_pars = 0;
	rt->res_pars = 0;
	rt->tabu = " \t\v\n\r\f";
	rt->objs = NULL;
}

int				main(int argc, char **argv)
{
	t_minirt	*rt;

	if (!(rt = malloc(sizeof(t_minirt))))
		ft_err_ex_minirt(rt, "Fail to malloc");
	ft_inicializate_t_minirt(rt);
	if (argc == 1 || argc > 3 || (argc == 3 && ft_strcmp(argv[2],
		"--save") != 0))
		ft_err_ex_minirt(rt, "Invalid arguments.");
	if (!ft_check_rt_file(argv[1]))
		ft_err_ex_minirt(rt, "Invalid arguments.");
	if (argc == 3)
		rt->bmp = 1;
	ft_open_rt_file(argv[1], rt);
	if (rt->res_pars != 1)
		ft_err_ex_minirt(rt, "Invalid permission!");
	if (rt->amb_pars != 1)
		ft_err_ex_minirt(rt, "Invalid ambient!");
	ft_check_cam_count(rt);
	ft_raytrace_start(rt);
	exit(0);
}
