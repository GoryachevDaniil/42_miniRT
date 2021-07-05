/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:25:41 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 19:42:07 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

void	ft_free_array(char ***arr)
{
	int	i;

	i = -1;
	while ((*arr)[++i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
	}
	free((*arr));
	(*arr) = NULL;
}

void	ft_free_all_split(t_minirt *rt)
{
	if (rt->split)
		ft_free_array(&rt->split);
	if (rt->split_xyz)
		ft_free_array(&rt->split_xyz);
	if (rt->split_xyz_n)
		ft_free_array(&rt->split_xyz_n);
	if (rt->split_xyz_2)
		ft_free_array(&rt->split_xyz_2);
	if (rt->split_xyz_3)
		ft_free_array(&rt->split_xyz_3);
	if (rt->split_rgb)
		ft_free_array(&rt->split_rgb);
}

void	ft_check_rgb_2(int *r, int *g, int *b)
{
	if (*r < 0)
		*r = 0;
	if (*r > 255)
		*r = 255;
	if (*g < 0)
		*g = 0;
	if (*g > 255)
		*g = 255;
	if (*b < 0)
		*b = 0;
	if (*b > 255)
		*b = 255;
}
