/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:20:34 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 02:03:09 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

static int	ft_check_is_digit(t_minirt *rt, char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '.')
	{
		if (s[i] == '.')
			i++;
		if (s[i] < '0' || s[i] > '9')
			ft_err_ex_minirt(rt, "Invalid argument");
		i++;
	}
	return (0);
}

static int	ft_overflow(int s)
{
	if (s >= 214748364)
		return (1);
	if (s <= -214748364)
		return (1);
	return (0);
}

int			ft_atoi_rt(char *str, t_minirt *rt)
{
	int		i;
	int		k;
	int		s;

	s = 0;
	k = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	ft_check_is_digit(rt, &str[i]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		s = s * 10 + str[i] - '0';
		i++;
		if (ft_overflow(s))
			return (s * k);
	}
	return (s * k);
}
