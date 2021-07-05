/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:24:53 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 19:39:27 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

void		ft_check_normla_xyz(float nx, float ny, float nz, t_minirt *rt)
{
	if (nx > 1 || nx < -1 || ny > 1 || ny < -1 || nz > 1 || nz < -1)
		ft_err_ex_minirt(rt, "Invalid normalized orientation vector.");
	if (nx == 0 && ny == 0 && nz == 0)
		ft_err_ex_minirt(rt, "Invalid normalized orientation vector.");
}

t_color		ft_check_rgb(t_minirt *rt, t_color color)
{
	if (color.r < 0 || color.r > 255 || color.g < 0
		|| color.g > 255 || color.b < 0 || color.b > 255)
		ft_err_ex_minirt(rt, "Invalid color.");
	return (color);
}

int			ft_check_split(char **arr)
{
	int		count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	return (count);
}

int			ft_check_rt_file(char *argv)
{
	int		i;

	i = 0;
	if (argv[i] == '.')
		return (0);
	while (argv[i] != '.')
		i++;
	i++;
	if (argv[i] == 'r' && argv[i + 1] == 't' && argv[i + 2] == '\0')
		return (1);
	return (0);
}

void		ft_check_cam_count(t_minirt *rt)
{
	t_list	*tmp;

	tmp = rt->cam;
	if (tmp == NULL)
		ft_err_ex_minirt(rt, "No camera, man!\nMake one more and come back.");
}
