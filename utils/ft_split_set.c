/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:19:01 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/10 13:47:16 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"
#include "get_next_line.h"

static int		chr(char c, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	kolvo(char const *s, char *set)
{
	int			count;
	int			is_word;

	is_word = 0;
	count = 0;
	while (*s)
	{
		if (chr(*s, set))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	syb(char const *s, int pos, char *set)
{
	size_t		len;

	len = 0;
	while (s[pos])
	{
		if (chr(s[pos], set))
			return (len);
		len++;
		pos++;
	}
	return (len);
}

char			**ft_split_set(char const *s, char *set)
{
	char		**tab;
	int			i;
	int			j;
	int			k;

	i = -1;
	j = 0;
	k = 0;
	if (!(tab = malloc(sizeof(char*) * (kolvo(s, set) + 1))))
		return (NULL);
	while (s[++i])
	{
		if (!chr(s[i], set))
		{
			if (k == 0)
				if (!(tab[j] = malloc(sizeof(char) * syb(s, i, set) + 1)))
					return (NULL);
			tab[j][k] = s[i];
			tab[j][++k] = '\0';
		}
		if ((chr(s[i], set) && !chr(s[i + 1], set) && k > 0) && (k = 0) == 0)
			j++;
	}
	tab[kolvo(s, set)] = NULL;
	return (tab);
}
