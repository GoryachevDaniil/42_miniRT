/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:08:13 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/13 19:20:50 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

static char	kolvo(t_minirt *rt, const char *s, char c)
{
	int		i;
	int		j;
	int		fail;

	fail = 0;
	i = 0;
	j = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
		{
			i = 0;
		}
		if (i == 0 && *s != c)
		{
			i = 1;
			j++;
		}
		if (*s == c)
			fail++;
		s++;
	}
	if (fail > 2)
		ft_err_ex_minirt(rt, "Invalid arguments.");
	return (j);
}

char		**ft_split(t_minirt *rt, char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**arr;

	i = 0;
	j = -1;
	if (!(arr = malloc(sizeof(char **) * (kolvo(rt, s, c) + 1))) || s == NULL)
		return (NULL);
	while (++j < kolvo(rt, s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = ft_substr(s, start, i - start);
	}
	arr[j] = NULL;
	return (arr);
}
