/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:57:57 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/10 13:47:38 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str[i] = '\0';
		return (str);
	}
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
