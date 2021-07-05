/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:02:23 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/10 13:45:59 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

void		*ft_calloc(unsigned num, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (void *)malloc(num * size);
	if (str == NULL)
		return (NULL);
	while (i < num * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
